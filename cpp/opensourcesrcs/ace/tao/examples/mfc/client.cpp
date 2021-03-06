// client.cpp,v 1.5 2001/03/05 13:59:02 mk1 Exp

#include "tao\corba.h"
#include "W32_TestC.h"
#include "tao\PortableServer\POA.h"

int
main (int argc, char *argv[])
{
  ACE_TRY_NEW_ENV
    {
      const char *orb_name = "";

      cout << "Initializing the ORB!" << endl;
      CORBA::ORB_var the_orb = CORBA::ORB_init (argc,
                                                argv,
                                                orb_name,
                                                ACE_TRY_ENV);
      ACE_TRY_CHECK;

      CORBA::Object_var orb_obj =
        the_orb->resolve_initial_references ("RootPOA", ACE_TRY_ENV);
      ACE_TRY_CHECK;

      PortableServer::POA_var the_root_poa =
        PortableServer::POA::_narrow (orb_obj.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;

      PortableServer::POAManager_var the_poa_manager =
        the_root_poa->the_POAManager (ACE_TRY_ENV);
      ACE_TRY_CHECK;

      // Retrieving the servants IOR from a file
      cout << "Reading the IOR!" << endl;

      const char *filename =
        "file://ior.txt";

      orb_obj =
        the_orb->string_to_object (filename, ACE_TRY_ENV);
      ACE_TRY_CHECK;

      cout << "Narrowing the IOR!" << endl;

      W32_Test_Interface_var mycall =
        W32_Test_Interface::_narrow (orb_obj.in (), ACE_TRY_ENV);
      ACE_TRY_CHECK;

      cout << "Sending the Request!" << endl;
      char *response = mycall->getresponse (1);
      cout << "The answer ..." << response << endl;

      // Free up the string.
      CORBA::string_free (response);
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Catched exception:");
      return 1;
    }
  ACE_ENDTRY;
  ACE_CHECK_RETURN (-1);

  return 0;
}
