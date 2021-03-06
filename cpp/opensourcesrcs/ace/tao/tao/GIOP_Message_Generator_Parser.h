
// -*- C++ -*-
// ===================================================================
/**
 *  @file   GIOP_Message_Generator_Parser.h
 *
 *  GIOP_Message_Generator_Parser.h,v 1.6 2001/05/09 19:02:05 parsons Exp
 *
 *  @author Balachandran Natarajan <bala@cs.wustl.edu>
 */
// ===================================================================

#ifndef TAO_GIOP_MESSAGE_GENERATOR_PARSER_H
#define TAO_GIOP_MESSAGE_GENERATOR_PARSER_H
#include "ace/pre.h"

#include "tao/corbafwd.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Exception.h"

#if defined(_MSC_VER)
#if (_MSC_VER >= 1200)
#pragma warning(push)
#endif /* _MSC_VER >= 1200 */
#pragma warning(disable:4250)
#endif /* _MSC_VER */

class TAO_Operation_Details;
class TAO_Target_Specification;
class TAO_OutputCDR;
class TAO_InputCDR;
class TAO_Pluggable_Reply_Params;
class TAO_Pluggable_Reply_Params_Base;
class TAO_GIOP_Locate_Status_Msg;
class TAO_GIOP_Locate_Request_Header;
class TAO_Tagged_Profile;

/**
 * @class TAO_GIOP_Message_Generator_Parser
 *
 * @brief Base class for the GIOP Message generator and parser
 *
 * Version specific classes would inherit from this class. Strategy to
 * determine which version of the GIOP request have we received and
 * which version do we need to use to send messages.
 */

class TAO_Export TAO_GIOP_Message_Generator_Parser
{
public:

  /// Write the request header in to <msg>
  virtual int write_request_header (
      const TAO_Operation_Details &opdetails,
      TAO_Target_Specification &spec,
      TAO_OutputCDR &msg) = 0;

  /// Write the LocateRequest header
  virtual int write_locate_request_header (
      CORBA::ULong request_id,
      TAO_Target_Specification &spec,
      TAO_OutputCDR &msg) = 0;

  /// Write the reply header in to <output>
  virtual int write_reply_header (
      TAO_OutputCDR &output,
      TAO_Pluggable_Reply_Params_Base &reply,
      CORBA::Environment &ACE_TRY_ENV)
    ACE_THROW_SPEC ((CORBA::SystemException)) = 0;

  /// Writes the locate _reply message in to the <output>
  virtual int write_locate_reply_mesg (
      TAO_OutputCDR &output,
      CORBA::ULong request_id,
      TAO_GIOP_Locate_Status_Msg &status) = 0;

  /// Parse the Request Header from the incoming stream. This will do a
  /// version specific parsing of the incoming Request header
  virtual int parse_request_header (TAO_ServerRequest &) = 0;

  /// Parse the Loacte Request Header from the incoming stream. This will do a
  /// version specific parsing of the incoming Request header
  virtual int parse_locate_header (
      TAO_GIOP_Locate_Request_Header &) = 0;

  /// Parse the reply message
  virtual int parse_reply (TAO_InputCDR &input,
                           TAO_Pluggable_Reply_Params &params);

  /// Parse the locate reply message from the server
  virtual int parse_locate_reply (TAO_InputCDR &input,
                                  TAO_Pluggable_Reply_Params &params);

  /// Our versions
  virtual CORBA::Octet major_version (void) = 0;
  virtual CORBA::Octet minor_version (void) = 0;

  /// Is the messaging object ready for processing BiDirectional
  /// request/response?
  virtual int is_ready_for_bidirectional (void);

protected:

  /// Marshall the reply status
  void marshal_reply_status (TAO_OutputCDR &output,
                             TAO_Pluggable_Reply_Params_Base &reply);

  /// Unmarshals the received object key
  CORBA::Boolean unmarshall_object_key (TAO_ObjectKey &object_key,
                                        TAO_InputCDR &cdr);

  /// Unmarshall the IOP::TaggedProfile
  CORBA::Boolean unmarshall_iop_profile (TAO_Tagged_Profile &profile,
                                         TAO_InputCDR &cdr);

  /// Unmarshalls the GIOP::IORAddressingInfo
  CORBA::Boolean unmarshall_ref_addr (TAO_Tagged_Profile &profile,
                                      TAO_InputCDR &cdr);

};

#if defined (__ACE_INLINE__)
# include "tao/GIOP_Message_Generator_Parser.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /*TAO_GIOP_MESSAGE_GENERATOR_PARSER_H*/
