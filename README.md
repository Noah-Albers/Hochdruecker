# Selber aufsetzen

[Visual Studio Code](https://code.visualstudio.com/) installieren.

Erweiterung [PlatformIO](https://platformio.org/) für Visual Studio Code installieren.

In VS-Code über `PlatformIO > Open` die PIO Home Oberfläche öffnen.

Dort übert `Projects > Create New Project` ein neues Projekt mit dem Board ihrer wahl erstellen (Wir nutzen `AZ-Delivery ESP-32 Dev Kit C V4`).

Als Framework muss `Arduino` ausgewählt werden.

Nachdem das Projekt erstellt wurde müssen sie das Repo in den Projektordner ziehen.

In der Datei `src/CompileConfig.h` müssen noch einige Einstellungen verändert werden.

Am wichtigesten ist es alle LED-Pins in den Array `LED_PINS` einzutragen und die länge von diesem dementsprechend zu ändern.

Weiterhin müssen in die Variablen `BUTTON_PIN_SWITCH` und `BUTTON_PIN_TRIGGER` die Pins für die jeweilige Buttons eingetragen werden.
