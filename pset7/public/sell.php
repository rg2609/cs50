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
        else
        {
            // lookup symbol
            $stock = lookup($_POST["symbol"]);
            
            // capitalize symbol
            $stock["symbol"] = strtoupper($stock["symbol"]);
            $positions = CS50::query("SELECT * FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            $shares = CS50::query("SELECT shares FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
            $sell = $positions[0]["shares"] * $stock["price"];
            $transaction = 'SELL';
            CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?", $sell, $_SESSION["id"]); 
            CS50::query("INSERT INTO history (id, transaction, symbol, shares, price) VALUES (?, ?, ?, ?, ?)", $_SESSION["id"], $transaction, $stock["symbol"], $shares[0]["shares"], $stock["price"]);
            CS50::query("DELETE FROM portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $_POST["symbol"]);
        }
        redirect("/");
    }
    else
    {
        render("sell_form.php", ["title" => "Sell"]);
    }
