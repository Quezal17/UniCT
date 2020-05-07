<?php
$x = $_GET['x'];
$y = $_GET['y'];
$op = $_GET['op'];

if(is_numeric($x) && is_numeric($y)) {
    echo "<p>Risultato: ";
    switch($op) {
        case "somma":
            echo ($x+$y);
            break;
        case "differenza":
            echo ($x-$y);
            break;
        case "prodotto":
            echo ($x*$y);
            break;
        case "divisione":
            if($y == 0) {
                if($x < 0)
                    echo "-∞";
                else if($x == 0)
                    echo "indeterminato";
                else if($x > 0)
                    echo "∞";
            }else
                echo ($x/$y);
            break;
    }
    echo "</p>";
}else
    echo "<p><span class='red-text'>Errore</span>: i parametri inseriti non sono numeri validi</p>";

?>

