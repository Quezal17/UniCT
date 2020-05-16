function startCli(classe,currentIndexTerminal) {

    let currentIndexInput = 0;
    let directory = "";
    let commandList = {
        "help": function (parametro) {
            if (parametro === "")
                return `
                    <ul>
                        <li>help - Visualizza la lista dei comandi;</li>
                        <li>echo stringa - Stampa la stringa passata come parametro;</li>
                        <li>cd directory - Cambia directory specificata come parametro;</li>
                        <li>clear - Pulisce la shell;</li>
                        <li>calc <num1> [+ | - | * | /] <num2> - Calcola l'operazione data dall'operando;</li>
                    </ul>`;
            return `<p><span class="red-text">Errore</span>: Sintassi errata</p><p>Controlla la sintassi dei comandi digitando il comando help</p>`;
        },
        "echo": function (stringa) {
            if (stringa === "")
                return `<p><span class="red-text">Errore</span>: Sintassi errata</p><p>Controlla la sintassi dei comandi digitando il comando help</p>`;
            return `
                <p>`+ stringa + `</p>
            `;
        },
        "cd": function (stringa) {
            stringa = stringa.trim().split(' ');
            if (stringa.length === 1) {
                if (stringa != "")
                    directory = "~" + stringa;
                else
                    directory = "";
                return "";
            }
            return `<p><span class="red-text">Errore</span>: Sintassi errata</p><p>Controlla la sintassi dei comandi digitando il comando help</p>`;
        },
        "clear": function (parametro) {
            if (parametro === "") {
                $(classe+currentIndexTerminal+' .shell').html("");
                currentIndexInput = -1;
                return "";
            }
            return `<p><span class="red-text">Errore</span>: Sintassi errata</p><p>Controlla la sintassi dei comandi digitando il comando help</p>`;
        },
        "calc": function (valori) {
            return operazione(valori);
        }
    }


    // FUNZIONI

    function operazione(valori) {
            let index = currentIndexInput;
            valori = valori.trim().split(' ');
            if (valori.length === 3) {
                $.get("../php/operazioni.php", {x:valori[0], op:valori[1], y:valori[2]}, function(risultato) {
                    $(classe+currentIndexTerminal+' #response'+index).append(`<p>`+risultato+`</p>`);
                    $(classe+currentIndexTerminal+" .shell").scrollTop($(classe+currentIndexTerminal+' .shell').prop("scrollHeight"));
                });
                return "";
            }
            else
                return `<p><span class="red-text">Errore</span>: Sintassi errata</p><p>Controlla la sintassi dei comandi digitando il comando help</p>`;
    }

    function checkCommand(inputCommand) {
        let response = "";
        if (inputCommand !== "") {
            let command = inputCommand.split(' ', 1)[0].trim();
            if (command in commandList) {
                let parametro = "";
                let indexSpace = inputCommand.indexOf(' ');
                if (indexSpace > 0) {
                    parametro = inputCommand.substring(inputCommand.indexOf(' ') + 1).trim();
                }
                response = commandList[command](parametro);
            } else
                response = `<p><span class="red-text">Errore</span>: Comando sconosciuto</p><p>Controlla la lista dei comandi digitando il comando help</p>`;
        }
        return response;
    }

    function createResponse(response) {
        $(classe+currentIndexTerminal+' .shell').append(`
            <div id="response`+ currentIndexInput + `" class="response">` + response + `</div>
        `);
    }

    function createCommandLine() {
        $(classe+currentIndexTerminal+' .shell').append(`
            <div class="command-line">
                <div class="user-part"><span class="green-text">simone@simonePC</span>:<span class="blue-text">`+ directory + `</span>~$</div>
                <div class="text-part"><input type="text" id="input`+ currentIndexInput + `" class="input-command"></div>
            </div>
        `);

        $(classe+currentIndexTerminal+' #input' + currentIndexInput).focus();

        $(classe+currentIndexTerminal+' #input' + currentIndexInput).keypress(function (event) {
            if (event.which == 13) {
                let inputCommand = $(classe+currentIndexTerminal+' #input' + currentIndexInput);
                inputCommand.prop("disabled", true);
                createResponse(checkCommand(inputCommand.val().trim()));
                currentIndexInput++;
                createCommandLine();
            }
        });
    }

    createCommandLine();
}
