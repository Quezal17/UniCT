$(document).ready(function () {

    let currentIndex = 0;
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
                        <li>somma x y - Calcola la somma x + y. I numeri devono essere interi o decimali;</li>
                        <li>differenza x y - Calcola la differenza x - y. I numeri devono essere interi o decimali;</li>
                        <li>prodotto x y - Calcola il prodotto x * y. I numeri devono essere interi o decimali;</li>
                        <li>divisione x y - Calcola la divisione x / y. I numeri devono essere interi o decimali;</li>
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
                $('.shell').html("");
                currentIndex = -1;
                return "";
            }
            return `<p><span class="red-text">Errore</span>: Sintassi errata</p><p>Controlla la sintassi dei comandi digitando il comando help</p>`;
        },
        "somma": function (valori) {
            return operazione("somma",valori);
        },
        "differenza": function (valori) {
            return operazione("differenza",valori);
        },
        "prodotto": function (valori) {
            return operazione("prodotto",valori);
        },
        "divisione": function (valori) {
            return operazione("divisione",valori);
        }
    }


    // FUNZIONI

    function operazione(nome, valori) {
        let index = currentIndex;
            valori = valori.trim().split(' ');
            if (valori.length === 2) {
                $.get("../php/operazioni.php", {x:valori[0], y:valori[1], op:nome}, function(risultato) {
                    $('#response'+index).append(risultato);
                    $(".shell").scrollTop($('.shell').prop("scrollHeight"));
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
        $('.shell').append(`
            <div id="response`+ currentIndex + `" class="response">` + response + `</div>
        `);
    }

    function createCommandLine() {
        $('.shell').append(`
            <div class="command-line">
                <div class="user-part"><span class="green-text">simone@simonePC</span>:<span class="blue-text">`+ directory + `</span>~$</div>
                <div class="text-part"><input type="text" id="input`+ currentIndex + `" class="input-command"></div>
            </div>
        `);

        $('#input' + currentIndex).focus();

        $('#input' + currentIndex).keypress(function (event) {
            if (event.which == 13) {
                let inputCommand = $('#input' + currentIndex);
                inputCommand.prop("disabled", true);
                createResponse(checkCommand(inputCommand.val().trim()));
                currentIndex++;
                createCommandLine();
            }
        });
    }

    $('.terminale').draggable({
        handle: ".shell-header"
    });
    $('.terminale').resizable({
        minWidth: 300,
        minHeight: 200,
        handles: "all"
    });
    createCommandLine();
})