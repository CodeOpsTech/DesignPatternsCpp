// Diamond_i.cpp,v 1.4 2001/02/26 20:10:26 bala Exp

#include "Diamond_i.h"

Top_i::Top_i ()
{
  // no-op.
}

Top_i::~Top_i ()
{
  // No-op.
}

char *
Top_i::shape (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return CORBA::string_dup ("a point.");
}

Left_i::Left_i ()
{
  // No-op.
}

Left_i::~Left_i ()
{
  // No-op.
}

char *
Left_i::shape (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return CORBA::string_dup ("the left line");
}

char *
Left_i::color (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return CORBA::string_dup ("black");
}

Right_i::Right_i ()
{
  // no-op.
}

Right_i::~Right_i ()
{
  // no-op.
}

char *
Right_i::shape (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return CORBA::string_dup ("the right line");
}

char *
Right_i::color (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return CORBA::string_dup ("red");
  //
}

CORBA::Long
Right_i::width (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return 0;
}

Buttom_i::Buttom_i ()
{
  // no-op.
}

Buttom_i::~Buttom_i ()
{
  // no-op.
}

char *
Buttom_i::shape (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return CORBA::string_dup ("a diamond");
}

char *
Buttom_i::color (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return CORBA::string_dup ("translucent");
}

CORBA::Long
Buttom_i::width (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return 100;
}

char *
Buttom_i::name (CORBA::Environment &)
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
{
  return CORBA::string_dup ("Jubilee");
}
