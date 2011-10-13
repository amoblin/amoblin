var http = new XMLHttpRequest();
const AUTO_CLOSE_DELAY_SECONDS = 2;

function login(username) {
    password = localStorage.getItem(username);

    var intra_login_url = "https://6.6.6.6/login.html";
    var intra_login_data = {"username": username, "password": password,
        "buttonClicked": "4", redirect_url: "", err_flag: "0", };
    xmlhttp_post(intra_login_url, urlencode(intra_login_data), null);

    var inter_login_data = {userid: username, passwd: password,
        serivce: "internet", chap: "0", random: "internet", };
    inter_login_url = "http://10.78.17.3/fcgi/websAuth";
    xmlhttp_post(inter_login_url, urlencode(inter_login_data), null);
    return 0;
}

function logout() {
    var inter_logout_url = "http://10.78.17.3/fcgi/websLogout";
    xmlhttp_post(inter_logout_url, '', null);

    var intra_logout_url = "https://6.6.6.6/logout.html";
    var intra_logout_data = {"userStatus": "1", "err_flag": "0", "err_msg": "", }
    xmlhttp_post(intra_logout_url, urlencode(intra_logout_data), null);
    return 0;
}

function init() {
    if(localStorage["active"] == undefined) {
        localStorage["active"] = 0;
    }
    buildAccountItems();
}

function buildAccountItems() {
    var menu = document.getElementById("accounts");
    var children = menu.childNodes;
    for(var i=0; i < children.length; i++) {
        menu.removeChild( children[i] );
    }

    for( var i=0; i < localStorage.length; i++) {
        if (localStorage.key(i) == "active") {
            continue;
        }
        addItem(menu, localStorage.key(i));
    }
    if (localStorage["active"] != 0) {
        username = localStorage["active"];
        item = document.getElementById(username);
        item.getElementsByClassName("icon")[0].style.visibility = "visible";
    }
    menu.style.display="block";
}

function onlogin() {
    item = event.target.id ? event.target : event.target.parentNode;
    username = item.id;

    /* 没退出的话先退出 */
    if (localStorage["active"] != 0) {
        if( onlogout() != 0 ) {
            return 1;
        }
    }

    /*登陆 */
    if (login(username) == 0 ) {
        //notify("登陆成功！", 0.2);
        localStorage["active"] = username;
        item.getElementsByClassName("icon")[0].style.visibility = "visible";
        item.title = "在线";
        closePopup();
        chrome.tabs.create({"url": "http://www.baidu.com"});
    } else {
        item.title = "未知错误";
    }
    return 0;
}

function onlogout() {
    if (logout() != 0 ) {
        return 1;
    }
    //notify("退出认证！", 300);

    if ( localStorage["active"] != 0) {
        var item = document.getElementById(localStorage["active"]);
        item.getElementsByClassName("icon")[0].style.visibility = "hidden";
        localStorage["active"] = 0;
    }
    closePopup();
    return 0;
}

function addItem(menu, username) {
    var sample_item = document.getElementById("sample_item");
    var new_item = sample_item.cloneNode(true);
    new_item.id = username;
    new_item.name = username;
    new_item.className = "item";

    var span = document.createElement("span");
    var cont = document.createTextNode(username);
    span.appendChild(cont);
    new_item.appendChild(span);
    menu.appendChild(new_item);
}

function onAddAccount() {
    var username = document.getElementById("txtAccountID").value;
    var password = document.getElementById("txtAccountPassword").value;
    document.getElementById("txtAccountID").value = '';
    document.getElementById("txtAccountPassword").value = '';
    localStorage[username] = password;

    var menu = document.getElementById("accounts");
    addItem(menu, username);
    showMenu();
}

function clearAccount() {
    localStorage.clear();
    localStorage["active"] = 0;
    buildAccountItems();
    closePopup();
}

function showMenu() {
    document.getElementById("addAccount").style.visibility =  "hidden";
	document.getElementById("menu").style.display = "block";
	document.getElementById("addAccount").style.display = "none";
}

function showAddAccount() {
    document.getElementById("addAccount").style.visibility =  "hidden";
	document.getElementById("menu").style.display = "none";
	document.getElementById("addAccount").style.display = "block";
	document.getElementById("addAccount").style.visibility =  "visible";
    document.getElementById("txtAccountID").focus();
}

function showAbout() {
    document.getElementById("about").style.visibility =  "hidden";
	document.getElementById("menu").style.display = "none";
	document.getElementById("about").style.display = "block";
	document.getElementById("about").style.visibility =  "visible";
}

function urlencode(params) {
    var par = [];
    for( var key in params) {
        par.push(key + '=' + params[key]);
    }
    return par.join('&');
}

function handle_state_change() {
    switch(http.readyState) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            if(http.status == 200) {
                //alert(http.responseText);
            }
            break;
    }
}

function xmlhttp_post(url, params, handle_func) {
    http.open("POST", url, false);
    http.setRequestHeader("Content-type", "application/x-www-form-url");
    http.setRequestHeader("Connection", "close");
    http.setRequestHeader("Content-length", params.length);
    http.onreadystatechange = handle_func;
    http.send(params);
}

function form_post(url, params) {
    var form = document.createElement("form");
    form.action = url;
    form.method = "post";
    form.style.display = "none";
    for( var x in params) {
        var opt = document.createElement("input");
        opt.name = x;
        opt.value = params[x];
        form.appendChild(opt);
    }
    document.body.appendChild(form);
    form.submit();
}

function closePopup() {
    window.close();
}

function submitenter(form_id, e) {
    var keycode;
    if(window.event) {
        keycode = window.event.keyCode;
    } else if (e) {
        keycode = e.which;
    } else {
        return true;
    }

    if( keycode == 13) {
        onAddAccount();
        return false;
    } else {
        return true;
    }
}

function test() {
    /*
    setTimeout(function() {
        event.currentTarget.cancel();
    }, timeout * 1000);
    */
    //chrome.tabs.create({"url": "http://www.baidu.com"});
    notify("hello", 2);
    notify("world", 2);
}

function notify(message, timeout) {
    var icon = "../images/bistu.png";
    //var title = "[" + new Date().toLocaleTimeString() + "] This notification will close in " + AUTO_CLOSE_DELAY_SECONDS + " seconds";
    var title = " Auto Post ";
    var body = message;

    if (window.webkitNotifications) {
        if (window.webkitNotifications.checkPermission() == 0) {
            var popup = window.webkitNotifications.createNotification(icon, title, body);
            popup.ondisplay = function(event) {
                setTimeout(function() {
                    event.currentTarget.cancel();
                }, timeout);
            }
            popup.show();
        } else {
            window.webkitNotifications.requestPermission();
            return;
        }
    }
}
