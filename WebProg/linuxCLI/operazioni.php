<?php
$x = $_GET['x'];
$y = $_GET['y'];
$op = $_GET['op'];

if(is_numeric($x) && is_numeric($y)) {
    switch($op) {
        case "somma":
            echo "Risultato: " . ($x+$y);
            break;
        case "differenza":
            echo "Risultato: " . ($x-$y);
            break;
        case "prodotto":
            echo "Risultato: " . ($x*$y);
            break;
        case "divisione":
            if($y == 0) {
                if($x < 0)
                    echo "Risultato: -∞";
                else if($x == 0)
                    echo "Risultato: indeterminato";
                else if($x > 0)
                    echo "Risultato: ∞";
            }else
                echo "Risultato: " . ($x/$y);
            break;
    }
}else
    echo "<span class='red-text'>Errore</span>: i parametri inseriti non sono numeri validi";

?>

