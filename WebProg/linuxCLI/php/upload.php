<?php
$target_dir = "./uploads/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;

if($_SERVER["REQUEST_METHOD"] == "POST") {
  
    if (file_exists($target_file)) {
        echo "Errore, il file è già presente.";
        $uploadOk = 0;
    }
  
    if ($_FILES["fileToUpload"]["size"] > 80000000) { // 80MB
        echo "Errore, il file è troppo grande.";
        $uploadOk = 0;
    }

  if ($uploadOk) {
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
      echo "Il file ". basename( $_FILES["fileToUpload"]["name"]). " è stato caricato.";
    } else {
      echo "Errore durante il caricamento del file ". basename( $_FILES["fileToUpload"]["name"]). ".";
    }
  }

}
?>