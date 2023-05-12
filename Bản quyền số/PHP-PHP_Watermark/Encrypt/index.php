
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Encrypt/Decrypt</title>
    <!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/css/bootstrap.min.css">

    <!-- jQuery library -->
    <script src="https://cdn.jsdelivr.net/npm/jquery@3.6.0/dist/jquery.slim.min.js"></script>

    <!-- Popper JS -->
    <script src="https://cdn.jsdelivr.net/npm/popper.js@1.16.1/dist/umd/popper.min.js"></script>

    <!-- Latest compiled JavaScript -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.1/dist/js/bootstrap.bundle.min.js"></script>
</head>
<body class = "bg-info">
<div class="container">
    <div class="row">
        <div class="col-md-8 offset-md-2 bg-light p-4 mt-5 rounded">
            <form action="action.php" method="POST">
                <div class="form-group">

                    <label for="message">Message</label>
                    <textarea name="text" id="msg" class="form-control" cols="30" rows="3" placeholder="Enter Message"></textarea>
                </div>
                <button type="submit" name="encrypt" class="btn btn-primary">Encrypt</button>
                <button type="submit" name="dencrypt" class="btn btn-primary">Dencrypt</button>
            </form>
        </div>
    </div>
</div>
</body>
</html>