// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Projekt: Othello (Reversi)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 08 Projekt Othello (Reversi).cpp -->
// <!-- slides/projects/project_200_othello.cpp -->

// %% [markdown]
//
// # Projekt: Othello (Reversi)
//
// Othello, auch bekannt als Reversi, ist ein Strategiespiel für zwei Spieler,
// das auf einem 8x8-Brett gespielt wird. In diesem Projekt implementieren Sie
// das Spiel Othello in C++.
//
// Eine Beispielimplementierung des Spiels finden Sie auf
// [GitHub](https://github.com/hoelzl/Reviser).

// %% [markdown]
//
// ## Spielregeln
//
// - Gespielt auf einem 8x8-Brett. Ein Spieler hat dunkle Steine, der andere
//   helle.
// - Die Anfangskonfiguration des Bretts hat 2 dunkle und 2 helle Steine in der
//   Mitte.
// - Die Spieler setzen abwechselnd Steine. Ein Stein muss so gesetzt werden,
//   dass er gegnerische Steine "einschließt" - es muss eine zusammenhängende
//   Linie von gegnerischen Steinen zwischen dem neuen Stein und einem anderen
//   Stein des aktuellen Spielers geben.
// - Alle eingeschlossenen gegnerischen Steine werden auf die Farbe des
//   aktuellen Spielers umgedreht.
// - Wenn ein Spieler keinen legalen Zug hat, setzt er aus. Das Spiel endet,
//   wenn kein Spieler mehr einen legalen Zug hat.
// - Der Spieler mit den meisten Steinen gewinnt. Das Spiel ist unentschieden,
//   wenn die Spieler die gleiche Anzahl von Steinen haben.

// %% [markdown]
//
// ## Beispiel
//
// Die folgende Ausgabe zeigt ein Beispiel für ein Othello-Spiel zwischen einem
// Mensch und einem Computer-Spieler. Die Spieler sind mit "*" und "O"
// gekennzeichnet.

// %% [markdown]
//
// ```
// Starting a new game.
// Dark player: The computer player
// Light player: The human
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | |*|O| | | |
// | | | |O|*| | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
//
// The computer player (dark) plays (6, 4).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | |*|O| | | |
// | | | |*|*| | | |
// | | | |*| | | | |
// | | | | | | | | |
// | | | | | | | | |
//
// Your possible moves are:
//    0:  4,  3
//    1:  6,  3
//    2:  6,  5
// Please select a move:
// 2
//
// The human (light) plays (6, 5).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | |*|O| | | |
// | | | |*|O| | | |
// | | | |*|O| | | |
// | | | | | | | | |
// | | | | | | | | |
//
// The computer player (dark) plays (5, 6).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | |*|O| | | |
// | | | |*|*|*| | |
// | | | |*|O| | | |
// | | | | | | | | |
// | | | | | | | | |
//
// Your possible moves are:
//    0:  3,  5
//    1:  4,  3
//    2:  4,  7
//    3:  6,  3
//    4:  6,  7
//    5:  7,  5
// Please select a move:
// 5
//
// The human (light) plays (7, 5).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | |*|O| | | |
// | | | |*|O|*| | |
// | | | |*|O| | | |
// | | | | |O| | | |
// | | | | | | | | |
//
// The computer player (dark) plays (6, 6).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | |*|O| | | |
// | | | |*|*|*| | |
// | | | |*|*|*| | |
// | | | | |O| | | |
// | | | | | | | | |
//
// Your possible moves are:
//    0:  3,  5
//    1:  4,  3
//    2:  5,  3
//    3:  5,  7
//    4:  6,  3
//    5:  6,  7
//    6:  8,  5
// Please select a move:
// 3
//
// The human (light) plays (5, 7).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | |*|O| | | |
// | | | |*|*|*|O| |
// | | | |*|*|O| | |
// | | | | |O| | | |
// | | | | | | | | |
//
// The computer player (dark) plays (7, 6).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | | |*|O| | | |
// | | | |*|*|*|O| |
// | | | |*|*|*| | |
// | | | | |O|*| | |
// | | | | | | | | |
//
// Your possible moves are:
//    0:  3,  5
//    1:  4,  3
//    2:  4,  8
//    3:  5,  3
//    4:  6,  3
//    5:  6,  7
//    6:  7,  7
//    7:  8,  4
//    8:  8,  5
// Please select a move:
// 1
//
// The human (light) plays (4, 3).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | |O|O|O| | | |
// | | | |*|*|*|O| |
// | | | |*|*|*| | |
// | | | | |O|*| | |
// | | | | | | | | |
//
// The computer player (dark) plays (5, 8).
// | | | | | | | | |
// | | | | | | | | |
// | | | | | | | | |
// | | |O|O|O| | | |
// | | | |*|*|*|*|*|
// | | | |*|*|*| | |
// | | | | |O|*| | |
// | | | | | | | | |
//
// Your possible moves are:
//    0:  3,  5
//    1:  4,  8
//    2:  5,  3
//    3:  6,  3
//    4:  6,  7
//    5:  7,  4
//    6:  7,  7
//    7:  8,  5
//    8:  8,  7
// Please select a move:
// 0
//
// The human (light) plays (3, 5).
// | | | | | | | | |
// | | | | | | | | |
// | | | | |O| | | |
// | | |O|O|O| | | |
// | | | |*|O|*|*|*|
// | | | |*|O|*| | |
// | | | | |O|*| | |
// | | | | | | | | |
//
// ...
//
// The computer player (dark) plays (4, 1).
// | | |O| |O|O| |O|
// |*| |O|O|O|O| |O|
// |*|*|*|O|O|O|O|O|
// |*|*|*|*|*|*|*|O|
// |*|*|*|*|*|O|*|O|
// |O| |*|*|*|O|O|O|
// |O|O|O|*|O|O|O|O|
// | |*|*| |*|*|*|O|
//
// Your possible moves are:
//    0:  1,  1
//    1:  1,  2
//    2:  1,  4
//    3:  2,  2
//    4:  2,  7
//    5:  6,  2
//    6:  8,  1
//    7:  8,  4
// Please select a move:
// 0
//
// The human (light) plays (1, 1).
// |O| |O| |O|O| |O|
// |O| |O|O|O|O| |O|
// |O|*|*|O|O|O|O|O|
// |O|*|*|*|*|*|*|O|
// |O|*|*|*|*|O|*|O|
// |O| |*|*|*|O|O|O|
// |O|O|O|*|O|O|O|O|
// | |*|*| |*|*|*|O|
//
// The computer player (dark) plays (8, 4).
// |O| |O| |O|O| |O|
// |O| |O|O|O|O| |O|
// |O|*|*|O|O|O|O|O|
// |O|*|*|*|*|*|*|O|
// |O|*|*|*|*|O|*|O|
// |O| |*|*|*|*|O|O|
// |O|O|O|*|*|O|O|O|
// | |*|*|*|*|*|*|O|
//
// Your possible moves are:
//    0:  1,  2
//    1:  1,  4
//    2:  2,  2
//    3:  2,  7
//    4:  6,  2
//    5:  8,  1
// Please select a move:
// 5
//
// The human (light) plays (8, 1).
// |O| |O| |O|O| |O|
// |O| |O|O|O|O| |O|
// |O|*|*|O|O|O|O|O|
// |O|*|*|*|O|*|*|O|
// |O|*|*|O|*|O|*|O|
// |O| |O|*|*|*|O|O|
// |O|O|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
//
// The computer player (dark) plays (1, 7).
// |O| |O| |O|O|*|O|
// |O| |O|O|O|*| |O|
// |O|*|*|O|*|O|O|O|
// |O|*|*|*|O|*|*|O|
// |O|*|*|O|*|O|*|O|
// |O| |O|*|*|*|O|O|
// |O|O|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
//
// Your possible moves are:
//    0:  1,  4
//    1:  2,  2
//    2:  2,  7
//    3:  6,  2
// Please select a move:
// 2
//
// The human (light) plays (2, 7).
// |O| |O| |O|O|*|O|
// |O| |O|O|O|O|O|O|
// |O|*|*|O|*|O|O|O|
// |O|*|*|*|O|*|O|O|
// |O|*|*|O|*|O|O|O|
// |O| |O|*|*|*|O|O|
// |O|O|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
//
// The computer player (dark) plays (1, 4).
// |O| |O|*|*|*|*|O|
// |O| |*|*|O|O|O|O|
// |O|*|*|*|*|O|O|O|
// |O|*|*|*|O|*|O|O|
// |O|*|*|*|*|O|O|O|
// |O| |O|*|*|*|O|O|
// |O|O|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
//
// Your possible moves are:
//    0:  1,  2
//    1:  2,  2
//    2:  6,  2
// Please select a move:
// 2
//
// The human (light) plays (6, 2).
// |O| |O|*|*|*|*|O|
// |O| |*|*|O|O|O|O|
// |O|*|*|*|O|O|O|O|
// |O|*|*|O|O|*|O|O|
// |O|*|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
// |O|O|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
//
// The computer player (dark) plays (2, 2).
// |O| |O|*|*|*|*|O|
// |O|*|*|*|O|O|O|O|
// |O|*|*|*|O|O|O|O|
// |O|*|*|*|O|*|O|O|
// |O|*|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
// |O|O|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
//
// Your possible moves are:
//    0:  1,  2
// Please select a move:
// 0
//
// The human (light) plays (1, 2).
// |O|O|O|O|O|O|O|O|
// |O|O|O|*|O|O|O|O|
// |O|O|*|O|O|O|O|O|
// |O|O|*|*|O|*|O|O|
// |O|O|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
// |O|O|O|*|*|O|O|O|
// |O|O|O|O|O|O|O|O|
//
// GAME OVER.
// The human (light) won.
// The score was 55:9.
// ```

// %% [markdown]
//
// # Implementierung
//
// Implementieren Sie das Spiel Othello/Reversi in C++. Das Spiel sollte
// folgendes unterstützen:
//
// - Eine 8x8-Brett-Repräsentation
// - Platzieren von Steinen auf dem Brett gemäß den Regeln
// - Bestimmen von legalen Zügen für einen Spieler
// - Umdrehen von eingeschlossenen gegnerischen Steinen
// - Überprüfen des Spielendes und Bestimmen des Gewinners
// - Eine einfache Konsolen-Schnittstelle
// - Autonome Computer-Spieler
// - Mensch gegen Computer und Computer gegen Computer Spiele

// %% [markdown]
//
// ## Implementierungshinweise (Teil 1)
//
// Um die grundlegende Struktur des Spiels zu erstellen, können Sie folgende
// Schritte befolgen. Dabei werden Sie typischerweise nicht jede Klasse in einem
// Schritt implementieren, sondern iterativ vorgehen und bereits implementierte
// Klassen immer wieder verfeinern.
//
// **Sie müssen sich nicht an diese Struktur halten, es gibt viele andere
// Möglichkeiten, das Spiel zu implementieren. Wenn Sie einen anderen Ansatz
// verfolgen möchten, ist das in Ordnung.**

// %% [markdown]
//
// - Beginnen Sie mit der Erstellung einer `Player`-Klasse, um die Informationen
//   jedes Spielers zu verwalten. Dazu gehören der Name des Spielers und die
//   Farbe.
// - Implementieren Sie eine `Score`-Klasse, um den Spielstand zu verwalten.
// - Implementieren Sie eine `Field`-Aufzählung, um das Spielbrett zu verwalten.
//   `Field` enthält Werte, die angeben, ob ein Feld leer, dunkel oder hell ist.
// - Implementieren Sie eine `Position`-Klasse, die die Positionen auf dem
//   Spielfeld enthält.
// - Erstellen Sie eine `Board`-Klasse, um das Spielbrett zu verwalten. Diese
//   Klasse verwendet `Field` und `Position`, um den Zustand des Bretts zu
//   verfolgen.
// - Erstellen Sie dann eine `Game`-Klasse, um die Spiel-Schleife und den
//   Spielzustand zu verwalten. Diese Klasse verwendet Instanzen von `Player`
//   und `Board`.
// - Implementieren Sie eine Klasse `Notifier`, um Benachrichtigungen und
//   Updates über das Spiel zu verwalten. (Wenn Sie etwas über Designmuster
//   wissen, handelt es sich hierbei um eine Anwendung des Beobachtermusters)
// - Implementieren Sie schließlich `GameResult`, um das Ergebnis des Spiels zu
//   verfolgen und am Ende des Spiels anzuzeigen.

// %% [markdown]
//
// Diese Klassen bieten die grundlegende Struktur für das Spiel. Sie können
// Versionen des Spiels erstellen, die menschliche gegen menschliche,
// menschliche gegen Computer- und Computer gegen Computer-Spiele unterstützen.
// Sie können auch textbasierte und grafische Benutzeroberflächen oder sogar
// eine Client-Server-Version des Spiels implementieren.

// %% [markdown]
//
// Die nächsten Schritte werden die Implementierung der
// Befehlszeilenschnittstelle und der `Player`-Unterklassen für menschliche und
// Computer-Spieler sein.
//
// - Implementieren Sie eine `ConsoleNotifier`-Klasse, eine Unterklasse von
//   `Notifier`, um Updates und Benachrichtigungen über das Spiel in der Konsole
//   anzuzeigen.
// - Implementieren Sie eine `RandomPlayer`-Klasse, eine Unterklasse von
//   `Player`, um die Züge und das Verhalten des zufällig bewegenden KI-Spielers
//   zu handhaben.
// - Implementieren Sie `SimpleCommandLinePlayer`, eine weitere Unterklasse von
//   `Player`, um Benutzereingaben für das Bewegen von Steinen in einem auf der
//   Konsole gespielten Spiel zu handhaben.

// %% [markdown]
//
// Diese Struktur basiert auf der Implementierung des Spiels, die Sie auf
// [GitHub](https://github.com/hoelzl/Reviser) finden können. Falls Sie sich
// noch genauer an die Struktur dieses Beispiels halten möchten, finden Sie im
// zweiten Teil der Implementierungshinweise weitere Details zu den
// Memberfunktionen der einzelnen Klassen.

// %% [markdown]
//
// ## Implementierungshinweise (Teil 2)
//
// Die folgenden Hinweise sind detaillierter und beziehen sich auf die
// Implementierung der Memberfunktionen der Klassen, die im ersten Teil der
// Implementierungshinweise erwähnt wurden. Die Hinweise enthalten nicht alle
// Memberfunktionen der Klassen, decken aber viele der wichtigsten.

// %% [markdown]
//
// 1. `Player`-Klasse:
//    - `virtual void new_game();` : Diese Methode wird verwendet, um die
//      Einstellungen des Spielers zu initialisieren, wenn ein neues Spiel
//      beginnt.
//    - `virtual Position pick_move(const BasicBoard &board) const = 0;` : Dies
//      ist eine reine virtuelle Methode. Wenn sie in Unterklassen implementiert
//      wird, wählt sie einen Zug basierend auf dem aktuellen Zustand des
//      Spielbretts.
//    - `virtual void game_over();` : Diese Methode wird verwendet, um die
//      Einstellungen des Spielers aufzuräumen, wenn das Spiel vorbei ist.

// %% [markdown]
//
// 2. `Score`-Klasse
//     - Memberfunktionen, um die Anzahl der dunklen, hellen und leeren Felder
//       auf dem Brett, die Felder für einen bestimmten Spieler usw. zu
//       bestimmen.
//     - `bool is_tied() const;` : Diese Methode überprüft, ob das Spiel
//       unentschieden ist oder nicht.
//     - `std::tuple<const Player&, const Player&> compute_winner(...) const;` :
//       Diese Methode berechnet den Gewinner und Verlierer basierend auf der
//       Anzahl der Felder, die von jedem Spieler besetzt sind. Die Argumente
//       hängen davon ab, wie Sie die Spieler im Spiel verwalten.

// %% [markdown]
//
// 3. `Field`-Aufzählung:
//    - Freistehende Funktionen, um zu überprüfen, ob ein Feld leer oder besetzt
//      ist, wer das Feld besetzt, usw.

// %% [markdown]
//
// 4. `Position`-Klasse:
//    - `get_row() const;` : Diese Methode gibt die Zeile der Position zurück.
//    - `get_column() const;` : Diese Methode gibt die Spalte der Position
//      zurück.
//    - Sie können entweder einen integralen Typ, wie `unsigned int`, verwenden,
//      um die Zeile und Spalte zu repräsentieren, oder benutzerdefinierte Typen
//      für sie erstellen.
//    - `bool is_valid() const;` : Diese Methode überprüft, ob die Position auf
//      dem Brett gültig ist.
//    - `Position next_in_direction(Direction dir) const;` : Diese Methode gibt
//      die nächste Position in der angegebenen Richtung zurück.
//    - `std::size_t to_linear_index() const;` : Diese Methode konvertiert die
//      Position in einen linearen Index in ein Array.

// %% [markdown]
//
// 5. `Board`-Klasse:
//    - `virtual Field& operator[](Position pos) = 0;` : Diese Methode wird
//      verwendet, um auf das Feld an einer bestimmten Position auf dem Brett
//      zuzugreifen. Gibt es auch in einer `const`-Version.
//    - `void initialize(InitialBoardState initial_state);` Diese Methode
//      initialisiert das Brett.
//    - `bool is_empty(Position pos) const;` : Diese Methode überprüft, ob eine
//      Position auf dem Brett leer ist.
//    - `bool is_valid_move(PlayerColor pc, Position pos) const;` : Diese
//      Methode überprüft, ob ein Zug gültig ist oder nicht.
//    - `Moves find_valid_moves(PlayerColor pc) const;` : Diese Methode findet
//      und gibt alle möglichen gültigen Züge für einen Spieler zurück.
//    - `void play_move(PlayerColor pc, Position pos);` : Diese Methode lässt
//      einen Spieler einen Zug an einer bestimmten Position spielen.
//    - `Score compute_score() const;` : Diese Methode berechnet und gibt den
//      Spielstand zurück.

// %% [markdown]
//
// 6. `Game`-Klasse:
//    - `virtual void new_game(bool swap_payers) = 0;` : Diese Methode wird
//      verwendet, um ein neues Spiel zu starten, mit der Option, die
//      Reihenfolge, in der die Spieler ziehen zu tauschen.
//    - `virtual void run_game_loop() = 0;` : Diese Methode behandelt die
//      Spiel-Schleife, die die Abfolge von Schritten umfasst, die in jeder Runde
//      des Spiels stattfinden.
//    - `virtual std::shared_ptr<const GameResult> get_result() const = 0;`:
//      Diese Methode gibt das Ergebnis des Spiels zurück.

// %% [markdown]
//
// 7. `Notifier`-Klasse:
//    - `virtual void note_new_game(const Players& players, const BasicBoard&
//      board)`: Diese Methode wird verwendet, um die Spieler und das Brett über
//      den Beginn eines neuen Spiels zu informieren.
//    - `virtual void note_move(const Player& player, const Position& pos)`:
//      Diese Methode wird verwendet, um die Spieler und das Brett über einen Zug
//      zu informieren.
//    - `virtual void note_game_over(const GameResult& result)`: Diese Methode
//      wird verwendet, um die Spieler und das Brett über das Ende des Spiels zu
//      informieren.
//    - `virtual void display_message(std::string_view message) = 0;` : Diese
//      Methode zeigt eine Nachricht für den Benutzer an. Sie können diese
//      Methode verwenden, um die Implementierung einiger Unterklassen zu
//      vereinfachen: Wenn die Standardimplementierungen aller anderen Methoden
//      Ausgaben erzeugen, indem sie `display_message` aufrufen, können Sie nur
//      `display_message` in einigen Unterklassen überschreiben. (Andere
//      Unterklassen, z. B. für GUIs, müssen möglicherweise auch andere Methoden
//      überschreiben.)

// %% [markdown]
//
// 8. `GameResult`-Klasse:
//    - `virtual std::string to_string() const = 0;` : Diese Methode gibt das
//      Ergebnis des Spiels als Zeichenkette zurück.

// %% [markdown]
//
// 9. `ConsoleNotifier`-Klasse:
//    - `void display_message(std::string_view message) override;` : Diese
//      Methode zeigt eine Nachricht für den Benutzer in der Konsole an.

// %% [markdown]
//
// 10. `RandomPlayer`-Klasse:
//    - `Position pick_move(const BasicBoard &board) const override;` :
//      Diese Methode wählt einen zufälligen Zug aus den möglichen Zügen aus.

// %% [markdown]
//
// 11. `SimpleCommandLinePlayer`-Klasse:
//    - `Position pick_move(const BasicBoard &board) const override;` :
//      Diese Methode fordert den Benutzer auf, einen Zug auszuwählen und gibt
//      die ausgewählte Position zurück.
