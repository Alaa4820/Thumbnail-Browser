# Thumbnail-Browser
Il progetto richiede la creazione di un “Thumbnail Browser” ossia di
un'interfaccia grafica per la visualizzazione di una collezione di immagini. Le
immagini sono distribuite all’interno di diverse cartelle a seconda del loro
contenuto (ad esempio la cartella “uomini” conterrà immagini che ritraggono
uomini, “delfini” conterrà immagini il cui contenuto consiste in delfini, ecc.).
Scopo dell’applicazione è di visualizzare tutte le categorie di immagini, ma
anche di poter includere o escludere alcune categorie specifiche. La figura
sottostante rappresenta un mockup dell’applicazione.

![image](https://user-images.githubusercontent.com/101665044/190850985-dae6cdf5-db6f-45b5-9048-e7b49a22791f.png)

L’interfaccia deve essere in grado di:
- Caricare e visualizzare in modo casuale le miniature di tutte le
immagini contenute all’interno delle sottocartelle della cartella
“dataset”. Per ottenere i percorsi relativi a tutte le immagini all’interno
della cartella “dataset” si consiglia di utilizzare l’oggetto QDirIterator. Le
miniature devono avere una dimensione di 120x120 pixels e sotto di
esse deve essere riportata la categoria di appartenenza.
- Adattare il widget contenente le miniature in accordo alle dimensioni
della finestra dell’applicazione.
- Includere/escludere dalla visualizzazione le categorie. Tale funzionalità
può essere implementata utilizzando una checkbox per ciascuna
categoria in modo che abilitando/disabilitando quest’ultima le miniature
vengano mostrate/non mostrate.
- Includere una checkbox “Tutte” per consentire la visualizzazione di
tutte le categorie. Quando la seguente checkbox è abilitata anche tutte le
altre lo sono.
