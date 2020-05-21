$(document).ready(function() {

    var indexes = {
        "terminal": 0,
        "upload": 0
    };

    var appList = ["terminal","upload"];

    function getNextIndex(app) {
        switch(app) {
            case "terminal":
                indexes.terminal += 1;
                return indexes.terminal;
            case "upload":
                indexes.upload += 1;
                return indexes.upload;
            default:
                break;
        }
    }


    function printWindow(appName, index) {
        $('#desktop').append(`
            <div class="window `+appName+index+`">
                <div class="window-head">
                    <span></span>
                    <div class="icon-x-close">X</div>
                </div>
                <div class="window-content"></div>
            </div>
        `);
        // close window
        $('.'+appName+index+' .icon-x-close').on('click',function(){
            $(this).parent().parent().remove();
        });

        // window focus
        $('.'+appName+index).click(function() {
            $(".window").css("z-index", "10");
            $(this).css("z-index", "20");
        });

        // window draggable
        $('.'+appName+index).draggable({
            handle: '.window-head'
        });

        //window resizable
        $('.'+appName+index).resizable({
            minWidth: 300,
            minHeight: 200,
            handles: "all"
        });
        
        switch(appName) {
            case "terminal":
                startCli("."+appName,index);
                break;
            case "upload":
                startUpload(appName,index);
                break;
            default:
                break;
        }
    }

    //PRINT ICONS
    function printIcons() {
        for(let i=0; i<appList.length; i++) {
            $('#desktop').append(`
                <div class="icon `+appList[i]+`-icon"></div>
            `);
            $('.'+appList[i]+'-icon').draggable();
        }
    }

    // ICON LISTENERS
    function addIconListeners() {
        for(let i=0; i<appList.length; i++) {
            $(`.`+appList[i]+'-icon').dblclick(function() {printWindow(appList[i],getNextIndex(appList[i]))});
        }
    }

    printIcons();
    addIconListeners();
    
})

/*


        
*/