
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
// NOTICE OF COPYRIGHT                                                         //
//                                                                             //
// Copyright (C) 2023                                                          //
//                                                                             //
// Authors:								       //
//   [1] Andrés Felipe García Cárdenas*					       //
//   [2] Julian Andrés Salamanca Bernal**                                      //
//   [3] Diego Julián Rodríguez-Patarroyo***				       //         			           
//                                                                             //
//   [1] andrfgarciac@udistrital.edu.co (Licenciada Universidad Distrital)     //
//   [2] jasalamanca@udistrital.edu.co (profesor Universidad Distrital)        //
//   [3] djrodriguezp@udistrital.edu.co (profesor Universidad Distrital)       //
//									       //
//  *,** Grupo de Física e Informática (FISINFOR)		               //
//  *** Grupo de Laboratorio de Fuentes Alternas de Energía (LIFAE)	       //
//  *,**,*** Universidad Distrital Francisco José de Caldas (Bogotá, Colombia) //	
//                                                                             //
// Web page:								       //
//   https://github.com/fisinforgh/                                            //
//                                                                             //
// This program is free software; you can redistribute it and/or modify        //
// it under the terms of the GNU General Public License as published by        //
// the Free Software Foundation; either version 2 of the License, or           //
// (at your option) any later version.                                         //
//                                                                             //
// This program is distributed in the hope that it will be useful,             //
// but WITHOUT ANY WARRANTY; without even the implied warranty of              //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               //
// GNU General Public License for more details:                                //
//                                                                             //
//               http://www.gnu.org/copyleft/gpl.html                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#include <TQObject.h>
#include <RQ_OBJECT.h>

//Definiendo las clases
class TGWindow;
class TGMainFrame;
class TRootEmbeddedCanvas;
class TGComboBox;
class TGButton;
class TGLabel;
class TGTab;
class TCanvas;
class TLine;
class TLatex;
class TGTextButton;
class TGCompositeFrame;
class TGGroupFrame;
class TPaveText;
class TGHorizontalFrame;
class TGVerticalFrame;
class TPave;
class TMarker;
class TGeoManager;
class TGNumberEntry;

//Definiendo la clase principal
class MyMainFrame{
	RQ_OBJECT("MyMainframe")
   
   private:
   TGMainFrame *fMain; 
   TGCompositeFrame *fMainFrame4645;	   
   TGHorizontalFrame *fHorizontalFrame1240;   
   TGVerticalFrame *fVerticalFrameMENUS;
   TGGroupFrame *fGroupFrameMENU1;
   TGLabel *fLabelNUMFACTOR;         
   TGComboBox *fComboBoxNUMSFACTORS;
   TGLabel *fLabelVALUEA;
   TGComboBox *fComboBoxVALUESA;
   TGGroupFrame *fGroupFrameMENU2;      
   TGTextButton *fTextButtonSTART; 
   TGTextButton *fTextButtonCONCEPTS;   
   TGTextButton *fTextButtonHELP;
   TGTextButton *fTextButtonEXIT;  
   TGVerticalFrame *fVerticalFrameDIAGRAMS;
   TGTab *fTabAll;
   TGCompositeFrame *tab1CLASSICAL;
   TGCompositeFrame *tab2CIRCUIT;   
   TGCompositeFrame *tab3QUANTUM;   
   TRootEmbeddedCanvas *fRootEmbeddedCanvasDRAWCLASSICAL;   
   TRootEmbeddedCanvas *fRootEmbeddedCanvasDRAWCIRCUIT;
   TRootEmbeddedCanvas *fRootEmbeddedCanvasDRAWQUANTUM;
   TRootEmbeddedCanvas *fRootEmbeddedCanvasEXPLINATION;
   TGHorizontalFrame *fHorizontalFrameOPTIONS;
   TGTextButton *fTextButtonBACK;
   TGTextButton *fTextButtonCLEAR;   
   TGTextButton *fTextButtonNEXT;
   //Valor para avanzar 
   Int_t  Breakopt=0;
   
   
   
   //contenedor de iconos
   TString pathDIR_ICONS;
   
   //Valores para texto
   TLatex *l1;
   TLatex *l2;
   TLatex *l3;
   TLatex *l4;
   TLatex *l5;
   TLatex *l6;
   TLatex *l7;
   TLatex *l8;
   TLatex *l9;
   TLatex *l10;
   TLatex *l11;
   TLatex *l12;
   TLatex *l13;
   TLatex *l14;
   TLatex *l15;
   TLatex *l16;
   TLatex *l17;
   TLatex *l18;
   TLatex *l19;
   TLatex *l20;
   
   
   //Lineas
   TLine *lineaV1;
   TLine *lineaV2;
   TLine *lineaV3;
   TLine *lineaV4;
   TLine *lineaV5;
   TLine *lineaV6;
   TLine *lineaV7;
   TLine *lineaV8;
   TLine *lineaV9;
   TLine *lineaV10;
  
   TLine *lineaH1;
   TLine *lineaH2;
   TLine *lineaH3;
   TLine *lineaH4;
   TLine *lineaH5;
   TLine *lineaH6;
   TLine *lineaH7;
   TLine *lineaH8;
   TLine *lineaH9;
   TLine *lineaH10;
   TLine *lineaH11;
   TLine *lineaH12;
   TLine *lineaH13;
   TLine *lineaH14;
   TLine *lineaH15;
   TLine *lineaH16;
   TLine *lineaH17;
   TLine *lineaH18;
   TLine *lineaH19;
   TLine *lineaH20;
          
   //Variable para controlar el cambio de los tabs
   bool CTab = false; 
             
   public:
   MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
   //Welcome
   void DoWelcome();
   void DoSelection(Int_t); //Realiza la conexion entre comboboxes para elegir que opciones mostrar 
   
   //Inicio	
   void DoStart();
   void DoConcepts();
   void DoHelp();
   void DoClassical();
   void DoCircuit();
   void DoQuantum();
   void CondClassical();
   void CondQuantum();
   void CondCircuit();
   //Navegacion
   void DoConceptsClassical();
   void DoConceptsQuantum();
   void DoConceptsCircuit();
   void CambioTab(Int_t);
   void DoNext();
   void DoBack();
   void DoClear();
   //Destructor
   virtual ~MyMainFrame();
};
