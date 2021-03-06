/* -*- C++ -*- */
// Read_Buffer.i,v 4.2 1998/08/22 06:34:49 irfan Exp

// Accessor to the number of bytes in the buffer.

ACE_INLINE size_t
ACE_Read_Buffer::size (void) const
{
  ACE_TRACE ("ACE_Read_Buffer::size");
  return this->size_;
}

// The total number of characters replaced.

ACE_INLINE size_t
ACE_Read_Buffer::replaced (void) const
{
  ACE_TRACE ("ACE_Read_Buffer::replaced");
  return this->occurrences_;
}

ACE_INLINE ACE_Allocator *
ACE_Read_Buffer::alloc (void) const
{
  ACE_TRACE ("ACE_Read_Buffer::alloc");
  return this->allocator_;
}

