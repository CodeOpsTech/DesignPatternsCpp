/**
*Copyright (c) 2000-2001, Jim Crafton
*All rights reserved.
*Redistribution and use in source and binary forms, with or without
*modification, are permitted provided that the following conditions
*are met:
*	Redistributions of source code must retain the above copyright
*	notice, this list of conditions and the following disclaimer.
*
*	Redistributions in binary form must reproduce the above copyright
*	notice, this list of conditions and the following disclaimer in 
*	the documentation and/or other materials provided with the distribution.
*
*THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
*AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS
*OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
*EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
*PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
*PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
*SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*NB: This software will not save the world.
*/

/* Generated by Together */


#ifndef MENU_H
#define MENU_H


namespace VCF{

class MenuItem;
class ComponentEvent;

#define MENU_CLASSID	"7B6F28B5-3E3F-11d4-B555-00C04F0196DA"

class APPKIT_API Menu : public Component {
public:
	
	BEGIN_CLASSINFO(Menu, "VCF::Menu", "VCF::Component", MENU_CLASSID )
	OBJECT_PROPERTY( MenuItem, "rootMenuItem", Menu::getRootMenuItem, Menu::setRootMenuItem );	
	END_CLASSINFO(Menu)

	Menu();

	virtual ~Menu();

	MenuItem* getRootMenuItem();

	void setRootMenuItem( MenuItem* item );

	virtual void afterCreate( ComponentEvent* event ){};//no-op for now
private:
    MenuItem* m_rootMenuItem;
};

};
#endif //MENU_H