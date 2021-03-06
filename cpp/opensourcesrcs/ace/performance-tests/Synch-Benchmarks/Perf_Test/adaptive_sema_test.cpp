// adaptive_sema_test.cpp,v 1.1 1998/08/30 08:39:10 nanbor Exp

#define  ACE_BUILD_SVC_DLL
#include "ace/Synch.h"
#include "Adaptive_Lock_Performance_Test_Base.h"

ACE_RCSID(Synch_Benchmarks, adaptive_sema_test, "adaptive_sema_test.cpp,v 1.1 1998/08/30 08:39:10 nanbor Exp")

#if defined (ACE_HAS_THREADS)

class ACE_Svc_Export Adaptive_Sema_Test : public Adaptive_Lock_Performance_Test_Base
{
public:
  virtual int init (int, char *[]);

private:
  static ACE_Semaphore sema;
};

ACE_Semaphore Adaptive_Sema_Test::sema (1);

int
Adaptive_Sema_Test::init (int, char *[])
{
  ACE_Lock *lock;
  ACE_NEW_RETURN (lock,
                  ACE_Lock_Adapter<ACE_Semaphore> (Adaptive_Sema_Test::sema),
                  -1);

  return this->set_lock (lock);
}

ACE_SVC_FACTORY_DECLARE (Adaptive_Sema_Test)
ACE_SVC_FACTORY_DEFINE  (Adaptive_Sema_Test)

#if defined (ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION)
template class ACE_Lock_Adapter<ACE_Semaphore>;
#elif defined (ACE_HAS_TEMPLATE_INSTANTIATION_PRAGMA)
#pragma instantiate ACE_Lock_Adapter<ACE_Semaphore>
#endif /* ACE_HAS_EXPLICIT_TEMPLATE_INSTANTIATION */
#endif /* ACE_HAS_THREADS */
