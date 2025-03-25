# UART-styrd led
Ett enkelt program för att styra en LED-lampa via UART/seriell kommunikation på en Raspberry Pi Pico.


## Hårdvaruanslutning
- **LED** skall anslutas till **GPIO16** på Raspberry Pi Pico.
- **Seriell kommunikation** sker via USB eller UART-pinnar.

## Användning
### Förberedelse och kodladdning
Bygg programmet med följande kommandon:
```sh
cmake -B build
make -C build
```

Ladda den genererade ```.uf2```-filen till Raspberry Pi Pico genom att starta enheten i **BOOTSEL-läge** och kopiera över filen. **Eller** använda ```picotool``` för att ladda koden. De genererade filerna finns i ```./bin/```-katalogen.

### Kommandon
Via en seriell terminal kan följande kommandon skickas:
- ```on``` - tänder LED-lampan
- ```off``` - släcker LED-lampan

