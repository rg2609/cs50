<?php
    // configuration
    require("../includes/config.php"); 
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a stock symbol.");
        }
        if (empty($_POST["shares"]))
        {
            apologize("You must provide a number of shares.");
        }
        if (preg_match("/^\d+$/", $_POST["shares"])!=true)
        {
            apologize("You must provide a positive whole number of shares.");
        }
        // lookup symbol
        $stock = lookup($_POST["symbol"]);
        if ($stock===false)
        {
            apologize("Please provide a valid stock symbol.");
        }
        else
        {
        // calculate purchase total
        $buy = $_POST["shares"] * $stock["price"];
        $transaction = 'BUY';
        
        $rows = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
        $cash = $rows[0]['cash'];   
            // check if enough cash
            if ($buy>$cash)
            {
                apologize("You do not have enough cash to complete this purchase.");
            }
            else
            {
                // capitalize symbol
                $stock["symbol"] = strtoupper($stock["symbol"]);
                // update portfolio
                CS50::query("INSERT INTO portfolio (id, symbol, shares) VALUES (?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES (shares)", $_SESSION["id"], $stock["symbol"], $_POST["shares"]);
                
            // update cash
            CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?", $buy, $_SESSION["id"]);
            // update history
            CS50::query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $stock["symbol"], $_POST["shares"], $stock["price"]); 
            }
        // redirect to portfolio    
        redirect("/");
        }
    }
    else
    {
        render("buy_form.php", ["title" => "Buy"]);
    }
?>