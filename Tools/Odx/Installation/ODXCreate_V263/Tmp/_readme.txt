########################################################################################
#######'									'#######
#######'									'#######
#######'									'#######
#########           Alte OCNF-Dateien in ODXCreate einbinden         	       #########
#########             Include old OCNF files in ODXCreate		       #########
#######'									'#######
#######'									'#######
#######'									'#######
########################################################################################


Verwendung des ODXCreates:
Die Lage der konfig-Datei ist ausschlaggebend, restliche Dateien (SW, FDSProjectID) sind daher relativ zur konfig-Datei zu berücksichtigen.
Kommandozeilenaufruf muss immer den absoluten Pfad angeben.

Vorgehensweise CLI- Aufruf:
1.	ODXCreate V2.5x starten.
2.	alter OCNF Datei via GUI laden.
3.	Via GUI folgende Einstellungen aktualisieren (da die Lage der konfig-Datei ausschlaggebend ist, werden die restliche Dateien relativ zum konfig-Datei)
			a.	FDS Project ID xml neu geladen (Durch Klick auf "Import FDS project" Button )
			b.	SW-Daten neu laden. (Durch Klick auf Browse Button)
			c.	Unter Reiter „General Information“  "Path for ODX output" aktualisieren. (Durch Klick auf Browse Button)
			d.	als neues OCNF abspeichern. 
4.	In der Kommandozeilenaufruf bitte die absolute Pfade verwenden. Siehe Beispiele: unter \ODXCreate_V2xx\Tmp

___________________________________________________________________________________________________________________



Use of the ODXCreate:
The location of the config file is decisive, remaining files (SW, FDSProjectID) must therefore be considered relative to the config file.
Command line call must always specify the absolute path.

Procedure CLI call:
1. start ODXCreate V2.5x.
2. Load old OCNF file via GUI.
3. Update the following settings via GUI (because the location of the konfig-file is crucial, the remaining files are relative to the konfig-file)
			a.	FDS Project ID xml reloaded (By clicking on "Import FDS project" button )
			b.	Reload SW data. (By clicking on Browse button)
			c.	Under tab "General Information" update "Path for ODX output". (By clicking on Browse button)
			d. 	Save as new OCNF. 
4. In the command line call please use the absolute paths. See examples: under \ODXCreate_V2xx\Tmp



