// EC_ConsumerControl.cpp,v 1.1 2000/01/18 04:40:39 coryan Exp

#include "EC_ConsumerControl.h"

#if ! defined (__ACE_INdLINE__)
#include "EC_ConsumerControl.i"
#endif /* __ACE_INLINE__ */

ACE_RCSID(Event, EC_ConsumerControl, "EC_ConsumerControl.cpp,v 1.1 2000/01/18 04:40:39 coryan Exp")

TAO_EC_ConsumerControl::TAO_EC_ConsumerControl (void)
{
}

TAO_EC_ConsumerControl::~TAO_EC_ConsumerControl (void)
{
}

int
TAO_EC_ConsumerControl::activate (void)
{
  return 0;
}

int
TAO_EC_ConsumerControl::shutdown (void)
{
  return 0;
}

void
TAO_EC_ConsumerControl::consumer_not_exist (TAO_EC_ProxyPushSupplier *,
                                            CORBA::Environment &)
{
}

void
TAO_EC_ConsumerControl::system_exception (TAO_EC_ProxyPushSupplier *,
                                          CORBA::SystemException &,
                                          CORBA::Environment &)
{
}

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)

#elif defined(ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)

#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
