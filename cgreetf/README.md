# cgreetf

Ett litet program som läser en fil rad för rad och returnerar en hälsning utifrån flaggor, där bara den första flaggan räknas.

## Kompilering med CMake

```sh
cmake -B build
make -C build install
```

- Binärerna placeras i `./bin/`
- Standardinstallationssökväg: `~/.local/bin`

## Användning

```sh
cgreetf <filename>
```

**Exempel på indata (`./tests/greets2.txt`)**

```
Alice
Bob -v
Charlie --uppercase
David -xyz
```

**Exempel på utdata**

```
Hello, Alice!
Greetings, esteemed Bob! It is a pleasure to present you with this message: Hello!
HELLO, CHARLIE!
Unknown flag: -xyz
```

## Flaggor

| Flagga                     | Beskrivning                        |
|---------------------------|-----------------------------------|
| (ingen flagga)             | Standardhälsning                   |
| `-v`, `--verbose`  | Ger en mer formell hälsning        |
| `-u`, `--uppercase` | Skriver ut hälsningen i versaler  |

## Felhantering

- Om programmet körs utan en fil som argument, visas ett felmeddelande.
- Om filen inte kan öppnas, visas ett felmeddelande.
- Om en okänd flagga används, visas en varning men programmet fortsätter att köra.


