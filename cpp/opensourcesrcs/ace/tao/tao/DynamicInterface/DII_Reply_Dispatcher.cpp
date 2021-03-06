// DII_Reply_Dispatcher.cpp,v 1.10 2001/08/14 19:52:43 bala Exp




#include "DII_Reply_Dispatcher.h"


ACE_RCSID(DynamicInterface, DII_Reply_Dispatcher, "DII_Reply_Dispatcher.cpp,v 1.10 2001/08/14 19:52:43 bala Exp")



#include "Request.h"
#include "tao/Pluggable.h"
#include "tao/Environment.h"
#include "tao/GIOP_Message_State.h"
#include "tao/debug.h"
#include "tao/ORB_Core.h"
#include "tao/Pluggable_Messaging_Utils.h"

// Constructor.
TAO_DII_Deferred_Reply_Dispatcher::TAO_DII_Deferred_Reply_Dispatcher (
    const CORBA::Request_ptr req,
    TAO_ORB_Core *orb_core)
  : TAO_Asynch_Reply_Dispatcher_Base (orb_core),
    db_ (sizeof buf_,
         ACE_Message_Block::MB_DATA,
         this->buf_,
         orb_core->message_block_buffer_allocator (),
         orb_core->locking_strategy (),
         ACE_Message_Block::DONT_DELETE,
         orb_core->message_block_dblock_allocator ()),
    reply_cdr_ (&db_,
                ACE_Message_Block::DONT_DELETE,
                TAO_ENCAP_BYTE_ORDER,
                TAO_DEF_GIOP_MAJOR,
                TAO_DEF_GIOP_MINOR,
                orb_core),
    req_ (req)

{
}

// Destructor.
TAO_DII_Deferred_Reply_Dispatcher::~TAO_DII_Deferred_Reply_Dispatcher (void)
{
}

// Dispatch the reply.
int
TAO_DII_Deferred_Reply_Dispatcher::dispatch_reply (
    TAO_Pluggable_Reply_Params &params
  )
{
  this->reply_status_ = params.reply_status_;

  // Transfer the <params.input_cdr_>'s content to this->reply_cdr_
  (void) this->reply_cdr_.clone_from (params.input_cdr_);

  // Steal the buffer, that way we don't do any unnecesary copies of
  // this data.
  CORBA::ULong max = params.svc_ctx_.maximum ();
  CORBA::ULong len = params.svc_ctx_.length ();
  IOP::ServiceContext* context_list = params.svc_ctx_.get_buffer (1);
  this->reply_service_info_.replace (max, len, context_list, 1);

  if (TAO_debug_level >= 4)
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("(%P | %t):TAO_Asynch_Reply_Dispatcher::dispatch_reply:\n")));
    }

  ACE_TRY_NEW_ENV
    {
      // Call the Request back and send the reply data.
      this->req_->handle_response (this->reply_cdr_,
                                   this->reply_status_,
                                   ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      if (TAO_debug_level >= 4)
        {
          ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                               "Exception during reply handler");
        }
    }
  ACE_ENDTRY;

  // This was dynamically allocated. Now the job is done. Commit
  // suicide here.
  delete this;

  return 1;
}

void
TAO_DII_Deferred_Reply_Dispatcher::connection_closed (void)
{
  ACE_TRY_NEW_ENV
    {
      // Generate a fake exception....
      CORBA::COMM_FAILURE comm_failure (0,
                                        CORBA::COMPLETED_MAYBE);

      TAO_OutputCDR out_cdr;

      comm_failure._tao_encode (out_cdr,
                                ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Turn into an output CDR
      TAO_InputCDR cdr (out_cdr);

      this->req_->handle_response (cdr,
                                   TAO_PLUGGABLE_MESSAGE_SYSTEM_EXCEPTION,
                                   ACE_TRY_ENV);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      if (TAO_debug_level >= 4)
        {
          ACE_PRINT_EXCEPTION (
              ACE_ANY_EXCEPTION,
              "DII_Deferred_Reply_Dispacher::connection_closed"
            );
        }
    }
  ACE_ENDTRY;
}
