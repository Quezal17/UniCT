$(document).ready(function() {

    var indexes = {
        "terminal": 0,
        "upload": 0
    };

    var iconList = ["cli"];
    var appList = ["terminal"];

    function getNextIndex(app) {
        switch(app) {
            case "terminal":
                indexes.terminal += 1;
                return indexes.terminal;
            default:
                break;
        }
    }


    function printWindow(appName, index, title) {
        $('#desktop').append(`
            <div class="window `+appName+index+`">
                <div class="window-head">
                    <span>`+title+`</span>
                    <div class="icon-x-close">X</div>
                </div>
                <div class="window-content shell"></div>
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
            default:
                break;
        }
    }

    //PRINT ICONS
    function printIcons() {
        for(let i=0; i<iconList.length; i++) {
            $('#desktop').append(`
                <div class="icon `+iconList[i]+`-icon"></div>
            `);
            $(`.`+iconList[i]+'-icon').draggable({
                handle: `.`+iconList[i]+'-icon'
            });
        }
    }

    // ICON LISTENERS
    function addIconListeners() {
        for(let i=0; i<appList.length; i++) {
            $(`.`+iconList[i]+'-icon').dblclick(function() {printWindow(appList[i],getNextIndex(appList[i]),"simone@simonePC")});
        }
    }

    printIcons();
    addIconListeners();
    
})

/*


        
*/