#ifndef TAO_CONNECTOR_IMPL_CPP
#define TAO_CONNECTOR_IMPL_CPP

#include "tao/Connector_Impl.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#if !defined(__ACE_INLINE__)
#include "tao/Connector_Impl.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(tao, Connector_Impl, "Connector_Impl.cpp,v 1.2 2000/12/07 23:39:26 bala Exp")


template <class SVC_HANDLER>
TAO_Connect_Creation_Strategy<SVC_HANDLER>::
    TAO_Connect_Creation_Strategy (ACE_Thread_Manager* t,
                                   TAO_ORB_Core *orb_core,
                                   void *arg,
                                   CORBA::Boolean flag)
    : ACE_Creation_Strategy <SVC_HANDLER> (t),
      orb_core_ (orb_core),
      arg_ (arg),
      lite_flag_ (flag)
{

}

template <class SVC_HANDLER> int
TAO_Connect_Creation_Strategy<SVC_HANDLER>::make_svc_handler (SVC_HANDLER *&sh)
{
  if (sh == 0)
    ACE_NEW_RETURN (sh,
                    SVC_HANDLER (this->orb_core_,
                                 this->lite_flag_,
                                 this->arg_),
                    -1);
  return 0;
}


////////////////////////////////////////////////////////////////

template <class SVC_HANDLER>
TAO_Connect_Concurrency_Strategy<SVC_HANDLER>::
     TAO_Connect_Concurrency_Strategy (TAO_ORB_Core *orb_core)
       : orb_core_ (orb_core)
{
}

template <class SVC_HANDLER> int
TAO_Connect_Concurrency_Strategy<SVC_HANDLER>::
    activate_svc_handler (SVC_HANDLER *sh,
                          void *arg)
{
  if (ACE_Concurrency_Strategy<SVC_HANDLER>::activate_svc_handler (sh,
                                                                   arg) == -1)
    return -1;

  // If the wait strategy wants us to be registered with the reactor
  // then we do so.
  return sh->transport ()->wait_strategy ()->register_handler ();
}


#endif /*TAO_CONNECTOR_IMPL_CPP*/
