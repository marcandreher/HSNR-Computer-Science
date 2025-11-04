# Aufgabe 01: Ein erstes Beispiel (WS 2025/26)

Mit diesem kleinen C-Programm werden wir die Verwendung der Werkzeuge erkunden, mit denen wir aus Quellcode (demo.c) lauffähige Programm erzeugen können.

## Vorbereitung

1. Importieren Sie die Vorlage in ein neues Projekt. Am einfachsten geht das, wenn Sie das Projekt direkt von *git.ide3.de* importieren. (Alternativ können Sie auch ein neues Projekt erstellen, und den vorgegebenen Quellcode durch den Code der Vorlage ersetzen.)

2. Die Vorlage enthält noch Fehler, die eine Übersetzung des Programms verhindern. Entfernen Sie diese, indem Sie den roten Markierungen und ggf. Hilfestellungen der Entwicklungsumgebung folgen.

3. Führen Sie das Programm aus. Welches Ergebnis erhalten Sie?

Antwort: 903 (Summe 1 - 42)

4. Kommentieren Sie die Vorgabe `n=42` aus und aktivieren Sie stattdessen die Zeilen darüber, die `n` von der Konsole einlesen. Führen Sie das Programm erneut aus und geben Sie 100 ein. Welches Ergebnis erhalten Sie dann?

Antowrt: 5050 (1 - 100)

## In der Übung

5. In der Praxis werden Sie nicht nur mit existierenden Projekten arbeiten, wie hier vorgegeben, sondern müssen auch eigene Projekte anlegen. Legen Sie ein neues C-Projekt mit dem Namen "aufgabe-1b" an. Entfernen Sie die automatisch erzeugte Datei main.c und legen eine neue C-Quellcodedatei (Source File) mit dem Namen demo.c an. Kopieren Sie den Inhalt der demo.c Datei aus GIT in diese neue Datei. Wiederholen Sie für die neue Quell-Datei die Schritte 2 bis 4. Wie muss die Datei CMakeLists.txt angepasst werden, um das Projekt lauffähig zu machen?

6. Führen Sie das Programm mithilfe des Debuggers in Einzelschritten aus. Welchen Wert haben `n` und `summe` direkt nach Starten des Programms? Welchen Wert hat `summe` vor der ersten Ausführung der Zeilen 15, 16 und 17?

Antwort: n = 32758
summme = 0

7. Führen Sie das Programm erneut mit dem Debugger aus. Welchen Wert hat die Summe beim `printf` nach dem Addieren von 10, 30 und 50? Wie kann man das mithilfe des Debuggers einfach ermitteln?

8. Führen Sie das Programm erneut mit dem Debugger aus. Welche Zahl wird addiert, wenn die Summe 1500 überschreitet? Wie kann man das mithilfe des Debuggers einfach ermitteln?

## Zusatz-Aufgaben fürrtgeschrittene

9. Erzeugen Sie ein eigenes Git-Repository für Ihr aktualisiertes Programm, indem Sie in Schritt (1.) oben bereits einen Fork der Vorlage erstellt haben oder ein neues Projekt auf dem Git-Server anlegen ([Video](https://codi.ide3.de/s/hE8WVtVYs)).

10. Schreiben Sie Ihre Änderungen fest (*git add*, *git commit*) und laden Sie das Programm auf den Server hoch.
    Fo