// Intrusive_List_Node.cpp,v 4.1 2001/08/01 23:39:25 coryan Exp

#ifndef ACE_INTRUSIVE_LIST_NODE_C
#define ACE_INTRUSIVE_LIST_NODE_C

#include "ace/Intrusive_List_Node.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#if !defined (__ACE_INLINE__)
#include "ace/Intrusive_List_Node.inl"
#endif /* __ACE_INLINE__ */

ACE_RCSID(ace, Intrusive_List_Node, "Intrusive_List_Node.cpp,v 4.1 2001/08/01 23:39:25 coryan Exp")

template<class T>
ACE_Intrusive_List_Node<T>::ACE_Intrusive_List_Node (void)
  : prev_ (0)
  , next_ (0)
{
}

#endif /* ACE_INTRUSIVE_LIST_NODE_C */
