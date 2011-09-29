var params = {username: "", password: ""};
var http = new XMLHttpRequest();

function init() {
    load_options(params);
    buildAccountItems(params);
}

function buildAccountItems(params) {
    var menu = document.getElementById("accounts");
    var templateItem = document.getElementById("sample_item");
    var div = document.createElement("div");
    div.id= params.username;
    div.name= params.username;
    div.title = params.username;
    div.className = "item";

    if(params.username) {
        var span = document.createElement("span");
        var cont = document.createTextNode(params.username);
        span.appendChild(cont);
        div.appendChild(span);
    }
    menu.appendChild(div);
    menu.style.display="block";
}

function addAccount() {
    closePopup();
    var username = document.getElementById("txtAccountID").value;
    var password = document.getElementById("txtAccountPassword").value;
    save_options({username: username, password: password});
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

function xmlhttp_post(url, params) {
    http.open("POST", url, false);
    http.setRequestHeader("Content-type", "application/x-www-form-url");
    http.setRequestHeader("Connection", "close");
    http.setRequestHeader("Content-length", params.length);
    http.onreadystatechange=handle_state_change;
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

function login() {
    if (!params.username) {
        showAddAccount();
        return 0;
    }

    var intra_login_data = {username: params.username, password: params.password,
        buttonClicked: "4", redirect_url: "", err_flag: "0", };

    //form_post("https://6.6.6.6/login.html", intra_login_data);
    xmlhttp_post("https://6.6.6.6/login.html", urlencode(intra_login_data));
    return 0;

    var inter_login_data = {userid: params.username, passwd: params.password,
        serivce: "internet", chap: "0", random: "internet", };

    //form_post("http://10.78.17.3/fcgi/websAuth", inter_login_data);
    xmlhttp_post("http://10.78.17.3/fcgi/websAuth", urlencode(inter_login_data));
    closePopup();
}

function logout() {
    closePopup();
    //form_post("http://10.78.17.3/fcgi/websLogout", '');
    xmlhttp_post("http://10.78.17.3/fcgi/websLogout", '');

    var intra_logout_data = {userStatus: "1", err_flag: "0", err_msg: "", }
    xmlhttp_post("https://6.6.6.6/logout.html", urlencode(intra_logout_data));
}

function save_options(params) {
    for (var item in params) {
        localStorage[item] = params[item];
    }
}

function load_options(params) {
    for( var item in params) {
        params[item] = localStorage[item];
    }
}

function closePopup() {
    window.close();
}
