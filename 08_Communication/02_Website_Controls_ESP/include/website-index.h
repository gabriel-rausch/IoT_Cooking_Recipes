const char websiteIndex[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP Website</title>
    <style>
        body {
            font-family: Arial, Helvetica, sans-serif;
            max-width: 800px;
            margin: auto;
        }
        a {
            text-decoration: none;
            color: white;
            padding: 20px;
            background: grey;
            display: block;
            text-decoration: center;
            text-align: center;
        }
    </style>
</head>
<body>
    <h1>Hello IoT WPM</h1>

    <p>Manipulate the LED</p>
    <a href="/led/on">ON</a><br>
    <a href="/led/off">OFF</a>

    <p>Please note, this is a simple demo. E.g. the button should be handled via ajax to prevent the simple anchor redirect that ends up in leaving this page...</p>
</body>
</html>
)=====";