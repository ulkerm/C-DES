# Übung 1 - Lösung

## 1. Discrete Event Simulation (src/des)

### Lösungsidee
Ein Ereignis ist eine abstrakte Klasse event mit einem Zeitpunkt (int).
Die Ereignisse sind polymorph und die Priority Queue(class Simulator) ist Zeiger von Ereignissen nach deren Zeit sortiert.
ProduceEvent und ConsumeEvent sind klassen die von der Klasse Event abgeleitet sind. In diesen Klassen ist die abstrakte Methode (virtual void execute() = 0) überschrieben. In ProduceEvent werden Produkte(Event) erzeugt, die in einem Puffer abgelegt werden. Falls der Puffer voll ist, muss der Produzent warten. Buffer ist eine Klasse, die als private element in klassen (ProduceEvent und ConsumeEvent) benutzt wird, Damit beide Klassen den gleichen Puffer benutzen können,  wird pointer benutzt . In ConsumeEvent werden die erzeugte Produkte im Puffer verbraucht.

In Klasse Simulator werden Events in priority queue hinzugefügt falls sie ProduceEvent sind. Dafür wird eine Methode getstatus implementiert, um die Events zu untersheiden. Wenn ConsumeEvent erzeugt wird, dann funktioniert Methode step() und ein Event wird von der queue gelöscht.
Mit Methode run wird die Simulation bis zu einem bestimmten Zeitpunkt ausgeführt, nachdem sie entweder pausiert oder stoppt(beendet). 

### Testfälle
```
Uebung01 - Discrete Event Simulation (DES)
------  Testing run  ------
The time of the  ProduceEvent:  67
The time of the  ProduceEvent:  79
The time of the  ProduceEvent:  23
The time of the  ProduceEvent:  38
The time of the  ProduceEvent:  40
The time of the  ProduceEvent:  62
The time of the  ProduceEvent:  24
The time of the  ProduceEvent:  8
The time of the  ProduceEvent:  53
The time of the  ProduceEvent:  19
The time of the  ConsumeEvent:  40
The time of the  ConsumeEvent:  5
The time of the  ConsumeEvent:  12
The time of the  ConsumeEvent:  2
The time of the  ConsumeEvent:  67
The queue run till 72 and stopped!
[ 79  ]

------  Testing buffer full  ------
The time of the  ProduceEvent:  83
The time of the  ProduceEvent:  7
The time of the  ProduceEvent:  79
The time of the  ProduceEvent:  70
The time of the  ProduceEvent:  82
The time of the  ProduceEvent:  33
The time of the  ProduceEvent:  19
The time of the  ProduceEvent:  9
The time of the  ProduceEvent:  47
The time of the  ProduceEvent:  40
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  33
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  69
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  18
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  26
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  25
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  7
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  56
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  32
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  37
Buffer is full. Cannot add more data.
The time of the  ProduceEvent:  80
The time of the  ConsumeEvent:  33
The time of the  ConsumeEvent:  19
The time of the  ConsumeEvent:  29
The time of the  ConsumeEvent:  19
The time of the  ConsumeEvent:  21
The time of the  ConsumeEvent:  47
The time of the  ConsumeEvent:  32
The time of the  ConsumeEvent:  33
The time of the  ConsumeEvent:  56
The time of the  ConsumeEvent:  45
The queue run till 80 and stopped!
[ 82  83  ]

------  Testing Consume  ------
The time of the  ProduceEvent:  5
The time of the  ProduceEvent:  18
The time of the  ProduceEvent:  11
The time of the  ProduceEvent:  34
The time of the  ProduceEvent:  37
The time of the  ProduceEvent:  51
The time of the  ProduceEvent:  33
The time of the  ProduceEvent:  28
The time of the  ProduceEvent:  64
The time of the  ProduceEvent:  28
The time of the  ConsumeEvent:  40
The time of the  ConsumeEvent:  24
The time of the  ConsumeEvent:  46
The time of the  ConsumeEvent:  30
The time of the  ConsumeEvent:  3
The time of the  ConsumeEvent:  22
The time of the  ConsumeEvent:  16
The time of the  ConsumeEvent:  49
The time of the  ConsumeEvent:  24
The time of the  ConsumeEvent:  1
Buffer is empty. Cannot remove data.
The time of the  ConsumeEvent:  3
Buffer is empty. Cannot remove data.
The time of the  ConsumeEvent:  27
The queue is empty!
[ ]


Process finished with exit code 0
```