Instructiuni pentru buna rulare a jocului Minesweeper:

1.Descarcarea si instalarea bibliotecii.
  Am folosit biblioteca SFML 2.4.1.
  Aceasta poate fi descarcata de aici:http://www.sfml-dev.org/download/sfml/2.4.1/
  
  Continutul folderului descarcat va fi plasat intru-un folder creat in Program Files (x86)\CodeBlocks  numit "sfml".
  In setarile CodeBlocks-ului la "Compiler menu" selecta Global compiler settings apoi "Toolchain executables".
  Selectam Additional Paths si scriem calea pana la folderul bin din sfml (C:\CodeBlocks\sfml\bin)
  
  Apoi deschidem proiectul CodeBlocks. Selectam meniul Project apoi Build options., si apoi Search Directories.
  -Aici selectam subtabelul Compiler si adaugam folderul include din folderul sfml aflat in CodeBloks, fara a mentine cai relative.
  -Apoi selectam subtabelul Linker si adaugam folderul |lib gasit in folderul SFML din CodeBlocks, fara a mai mentine cai relative.

  In final la Project build options selectam Linker settings si adaugam librariile in aceasta ordine 
    a) sfml-graphics
    b) sfml-window
    c) sfml-system

2.Cum jucam?
   Apasam run, moment in care trebuie sa introducem numele jucatorului.
 
   Dupa aceasta vom fi intampinati de meniul jocului unde putem selecta gamemode-ul.
 Acest lucru il putem face selectand cu mouse-ul una din variante (Clasic/Mediu/Expert/Custom)
 
 In cazul primelor 3 variante acest lucru va duce la inceperea jocului in modul respectiv.
 
   In cazul variante Custom va trebui sa adaugam numarul de linii, coloane si mine.
 Acest lucru il facem selectand Custom apoi introducand de la tasatura numerele dorite
 despartite de tasta Enter. De exemplu pentru cand vrem sa avem 15 coloane, 10 linii si 20 de mine apasam:
 15 Enter 10 Enter 20 Enter. Lucrul pe care il introducem va fi specificat intr-o casuta. De exemplu in 
 momentul in care introducem liniile, pe ecran va fi o casuta pe care scrie "Linii"...
 Dupa ce Introducem numerele jocul va incepe.

   Jocul respecta toate regulile jocului original.

   Controale. Celula dorita poate fi selectata cu mouseul sau cu tastatura.
 Mouse:Selectarea se face cu ajutorul cursorului. Click stanga pentru descoperire celula, click dreapta pentru plasare stegulet.
 Tastatura: Selectarea celulei se va face cu ajutorul sagetilor. Celula pe care suntem va avea un outline rosu.
 Cand ajungem la celula dorita apasam "Enter" pentru descoperire si "Shift" pentru plasare stegulet.
 
   Pentru a vedea scorurile: In timpul in care suntem la meniu selectam cu mouse-ul casuta "Scoruri".
 Apoi selectam gamemode-ul de la care vrem sa vedem scorurile.
 De exemplu apasam "Scoruri" apoi "Clasic" pentru a vedea scorurile de la modul "Clasic".
 Aceasta actiune poate fi repetata de oricate ori vrem.

   Pentru a iesi din joc inchidem fereastra "Meniu" atunci cand ne aflam in ea.