//
// argument.cpp,v 1.5 1999/10/04 18:24:09 parsons Exp
//

// ============================================================================
//
// = LIBRARY
//    TAO IDL
//
// = FILENAME
//    argument.cpp
//
// = DESCRIPTION
//    generic visitor for Argument node
//
// = AUTHOR
//    Aniruddha Gokhale
//
// ============================================================================

#include "idl.h"
#include "be.h"
#include "be_visitor_argument.h"

ACE_RCSID(be_visitor_argument, argument, "argument.cpp,v 1.5 1999/10/04 18:24:09 parsons Exp")

be_visitor_args::be_visitor_args (be_visitor_context *ctx)
  : be_visitor_decl (ctx)
{
}

be_visitor_args::~be_visitor_args (void)
{
}

int be_visitor_args::visit_argument (be_argument *)
{
  return -1;
}

// helper that returns the type name either as a nested type name (for header
// files) or as a fully scoped name. In addition, we make sure that if the type
// is an alias, we use that name
const char *
be_visitor_args::type_name (be_type *node, 
                            const char *suffix)
{
  static char namebuf [NAMEBUFSIZE];
  ACE_OS::memset (namebuf, '\0', NAMEBUFSIZE);

  be_type *bt; // type to use

  // use the typedefed name if that is the one used in the IDL defn
  if (this->ctx_->alias ())
    bt = this->ctx_->alias ();
  else
    bt = node;

  ACE_OS::sprintf (namebuf, 
                   "%s", 
                   bt->full_name ());

  if (suffix)
    ACE_OS::strcat (namebuf, 
                    suffix);

  return namebuf;
}

// helper that returns the direction type of the argument
AST_Argument::Direction
be_visitor_args::direction (void)
{
  // grab the argument node. We know that our context has stored the right
  // argument node
  be_argument *arg = this->ctx_->be_node_as_argument ();

  ACE_ASSERT (arg != 0);
  return arg->direction ();
}
