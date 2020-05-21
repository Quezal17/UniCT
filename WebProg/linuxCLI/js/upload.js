function startUpload(appName, currentIndexWindow) {

    var identifier = appName + currentIndexWindow;

    function sendFileToServer() {
      
      var myFile = $(`input[data-id="input-file-`+currentIndexWindow+`"]`).prop('files')[0];
      var formData = new FormData();
      formData.append("fileToUpload", myFile);

      $.ajax({  
        url: "../php/upload.php", 
        method: 'POST',
        data: formData,
        cache: false,
        processData: false,
        contentType: false,
        xhr: function () {
          var myXhr = $.ajaxSettings.xhr();
          if (myXhr.upload) {
              myXhr.upload.addEventListener('progress', function (e) {
              if (e.lengthComputable) {
                $('.'+identifier+' .progress-bar .bar').width( (100 * e.loaded / e.total) + '%');
              }
            }, false);
          }
          return myXhr;
        },
        success: function(response) {
          $('.'+identifier+' .response').html(`<p>`+response+`</p>`);
        }
      });
    }

    function printForm() {
        $('.'+identifier+' .window-content').append(`
          <form enctype="multipart/form-data">
                <label for="input-file-`+currentIndexWindow+`">Scegli un file pdf da caricare:</label>
                <input type="file" name="fileToUpload" data-id="input-file-`+currentIndexWindow+`" value="male">
                <br><input type="button" name="button" value="Carica" data-id="btn-upload-`+currentIndexWindow+`">
            </form>
            <div class="progress-bar">
              <div class="bar"></div>
            </div>
            <div class="response"></div>
            
        `);

       $(`input[data-id="btn-upload-`+currentIndexWindow+`"]`).click(sendFileToServer);
       $(`input[data-id="input-file-`+currentIndexWindow+`"]`).click(function (){
          $('.'+identifier+' .progress-bar .bar').width(0);
          $('.'+identifier+' .response').html('');
       });
    }


    //setting window title
    $('.'+identifier+' .window-head span').text("File Upload");
    printForm();
}