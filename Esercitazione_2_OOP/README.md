Esercitazione sull’overload degli operatori

March 17, 2025

Questa esercitazione `e obbligatoria e dev’essere consegnata al massimo alla data di consegna prevista per l’esercitazione sull’input output. √ ![](Aspose.Words.4f360d99-6166-407f-a19c-6bedf7a11ad0.001.png)

Un numero complesso `e un numero della forma z = a+ ib, dove i = −1 `e l’unit`a immaginaria. I due numeri reali a e b sono detti rispettivamente parte reale e parte immaginaria.

Si definisca una classe template complex~~ number che modella i numeri complessi. La classe template prende come parametro il tipo Tcon il quale si rappresentano a e bsulla macchina. La classe deve funzionare correttamente per T = float e T = double.

Tale classe template deve:

- Avere un costruttore di default
- Avere un costruttore user-defined per l’inizializzazione di parte reale ed immaginaria
- Avere metodi che restituiscano il coniugato, la parte reale e la parte immaginaria
- Fornire un overload dell’operatore << per stampare il numero comp- lesso. Se per esempio a = 1 e b= 2, dev’essere stampato 1+2i, mentre se b= −2 dev’essere stampato 1-2i.
- Fornire un overload degli operatori += e +.
- Fornire un overload degli operatori \*= e \*.
- Opzionale: in modo simile a quanto fatto in classe nel caso di rational , utilizzare i concept per vincolare T ad essere un tipo floating poing. Verificare su [https://en.cppreference.com/w/cpp/header/concepts ](https://en.cppreference.com/w/cpp/header/concepts)qual’`e il concept da utilizzare a tal scopo.

Similmente a quanto fatto su rational, gli operatori + e \* implemen- tati devono soddisfare correttamente i requisiti di commutativit`a quando l’operazione svolta `e tra un complex~~ numer<T> ed un T.
2
