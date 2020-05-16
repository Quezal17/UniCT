<?php
if($_SERVER["REQUEST_METHOD"] == "GET") {
$x = $_GET['x'];
$y = $_GET['y'];
$op = $_GET['op'];

if(is_numeric($x) && is_numeric($y)) {
    $result="Result: ";
    switch($op) {
        case "+":
            $result .= strval($x + $y);
            break;
        case "-":
            $result .= strval($x - $y);
            break;
        case "*":
            $result .= strval($x * $y);
            break;
        case "/":
            if($y == 0) {
                if($x < 0)
                    $result .= "-∞";
                else if($x == 0)
                    $result .= "indeterminato";
                else if($x > 0)
                    $result .= "∞";
            }else
                $result .= strval($x / $y);
            break;
        default:
            $result = "<span class='red-text'>Errore</span>: Operando sconosciuto";
            break;
    }
    echo $result;
}else
    echo "<span class='red-text'>Errore</span>: i parametri inseriti non sono numeri validi";
}
?>

