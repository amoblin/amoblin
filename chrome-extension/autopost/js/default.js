function post(url, params) {
    var form = document.createElement_x("form");
    form.action = url;
    temp.method = "post";
    temp.style.display = "none";
    for( var x in params) {
        var opt = document.createElement_x("textarea");
        opt.name = x;
        opt.value = params[x];
        temp.appendChild(opt);
    }
    document.body.appendChild(temp);
    temp.submit();
    return temp;

}

function login(username, password) {
    post("https://6.6.6.6/login.html",
            {"username": username,
                "password": password,
            });

    post("http://10.78.17.3/fcgi/websAuth",
            {"userid": username,
                "passwd": password,
        "serivce": "internet",
        "chap": "0",
        "random": "internet",
            });
}

function logout(username, password) {
    post("http://10.78.17.3/fcgi/websLogout", {});

    post("https://6.6.6.6/logout.html", 
            {"userStatus": "1",
                "err_flag": "0",
        "err_msg": "",
            });
}

