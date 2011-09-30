var http = new XMLHttpRequest();

function login(username) {
    /*
    if (!localStorage["active"]) {
        showAddAccount();
        return 0;
    }
    */
    //closePopup();

    //username = localStorage.getItem("active");
    password = localStorage.getItem(username);
    /*
    var intra_login_url = "https://6.6.6.6/login.html";
    var intra_login_data = {"username": username, "password": password,
        "buttonClicked": "4", redirect_url: "", err_flag: "0", };
    xmlhttp_post(intra_login_url, urlencode(intra_login_data), null);
    window = chrome.tabs.create({"url": "http://baidu.com"});
    */

    var inter_login_data = {userid: username, passwd: password,
        serivce: "internet", chap: "0", random: "internet", };
    inter_login_url = "http://10.78.17.3/fcgi/websAuth";
    xmlhttp_post(inter_login_url, urlencode(inter_login_data), null);
    alert(password);
    window = chrome.tabs.create({"url": "http://baidu.com"});
    return 1;
}

function logout() {
    closePopup();
    var inter_logout_url = "http://10.78.17.3/fcgi/websLogout";
    xmlhttp_post(inter_logout_url, '', null);
    chrome.tabs.create({"url": inter_logout_url});

    var intra_logout_url = "https://6.6.6.6/logout.html";
    var intra_logout_data = {"userStatus": "1", "err_flag": "0", "err_msg": "", }
    xmlhttp_post(intra_logout_url, urlencode(intra_logout_data));
}

function init() {
    buildAccountItems();
}

function buildAccountItems() {
    var menu = document.getElementById("accounts");
    var children = menu.childNodes;
    for(var i=0; i < children.length; i++) {
        menu.removeChild( children[i] );
    }
    for( var i=0; i < localStorage.length; i++) {
        //alert(localStorage.key(i)+":"+localStorage[localStorage.key(i)]);
        if (localStorage.key(i) == "active") {
            continue;
        }
        addItem(menu, localStorage.key(i), 1);
    }
    menu.style.display="block";
}

function setDeActive(accounts) {
    /*
    */
    for (var i=0; i< accounts.childNodes.length; i++) {
        accounts.childNodes[i].onclick = null;
        accounts.childNodes[i].title = "当前状态不可用";
    }
}

function selectItem() {
    username = this.getAttribute("id");
    if (login(username) == 1 ) {
        setDeActive(this.parentNode);
        localStorage["active"] = username;
        this.firstChild.style.visibility = "visible";
        this.onclick = selectItem;
        this.title = "在线";
        closePopup();
    }
    return 0;
}

function unselect() {
    if (logout() == 1 ) {
        setActive();
        closePopup();
    }
}

function setActive() {
    var accounts = document.getElementById("accounts");
    for (var i=0; i< accounts.childNodes.length; i++) {
        accounts.childNodes[i].onclick = selectItem;
        accounts.childNodes[i].title = "点击登陆";
        accounts.childNodes[i].style.className = "visible";
    }

    if ( localStorage["active"] == undefined) {
        return 0;
    }

    var item = document.getElementById(localStorage["active"]);
    item.firstChild.style.visibility = "hidden";

    localStorage["active"] = undefined;
}
function addItem(menu, username, type) {
    var sample_item = document.getElementById("sample_item");
    var new_item = sample_item.cloneNode(true);
    new_item.id = username;
    new_item.name = username;
    new_item.className = "item";
    if(type == 0) {
        new_item.title = "当前状态不可用";
        new_item.onclick = null;
    }

    var span = document.createElement("span");
    var cont = document.createTextNode(username);
    span.appendChild(cont);
    new_item.appendChild(span);

    menu.appendChild(new_item);
}

function addAccount() {
    var username = document.getElementById("txtAccountID").value;
    var password = document.getElementById("txtAccountPassword").value;
    document.getElementById("txtAccountID").value = '';
    document.getElementById("txtAccountPassword").value = '';
    localStorage[username] = password;

    var menu = document.getElementById("accounts");
    if (localStorage["active"] == undefined || localStorage["active"] == "undefined") {
        addItem(menu, username, 1);
    } else {
        addItem(menu, username, 0);
    }
    showMenu();
}

function clearAccount() {
    localStorage.clear();
    buildAccountItems();
    closePopup();
}

function showMenu() {
    document.getElementById("addAccount").style.visibility =  "hidden";
	document.getElementById("menu").style.display = "block";
	document.getElementById("addAccount").style.display = "none";
}

function showAddAccount() {
	//var currentBodyDirection = document.body.style.direction;	// ....workaround for a Chrome bug
	//document.body.style.direction = "ltr";						// ....prevents resizing the popup
    document.getElementById("addAccount").style.visibility =  "hidden";
	document.getElementById("menu").style.display = "none";
	document.getElementById("addAccount").style.display = "block";
	//$(document.body).height($("#addAccount").height());
	//$(window).height($("#addAccount").height());

	//document.body.style.direction = currentBodyDirection;		// ....if the body's direction is "rtl"
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
            alert(http.readyState);
            break;
        case 1:
            alert(http.readyState);
            break;
        case 2:
            alert(http.readyState);
            break;
        case 3:
            alert(http.readyState);
            break;
        case 4:
            if(http.status == 200) {
                alert(http.responseText);
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
        addAccount();
        return false;
    } else {
        return true;
    }
}

