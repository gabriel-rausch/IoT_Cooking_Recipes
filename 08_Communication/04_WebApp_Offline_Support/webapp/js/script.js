window.addEventListener("load", function () {
    var btn = document.querySelector(".light");

    btn.addEventListener("click", function () {
        if (btn.classList.contains("inactive")) {
            btn.classList.remove("inactive");
            quickAndDirtyAjaxCall("/led/on");
        } else {
            btn.classList.add("inactive");
            quickAndDirtyAjaxCall("/led/off");
        }

    })

    function quickAndDirtyAjaxCall(url) {
        var xmlhttp = new XMLHttpRequest();
        xmlhttp.open("GET", url, true);
        xmlhttp.send();
    }
});