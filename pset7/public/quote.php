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
        // lookup symbol
        $stock = lookup($_POST["symbol"]);
        // if invalid, ask for valid symbol
        if ($stock===false)
        {
            apologize("Please provide a valid symbol.");
        }
        else
        // capitalize symbol
        $stock["symbol"] = strtoupper($stock["symbol"]);
		// render data for quote
        {
            render("quote_display.php", ["title" => "Quote", "symbol" => $stock["symbol"], "name" => $stock["name"], "price" => $stock["price"]]);
        }
    }
    else
	// display quote form
    {
        render("quote_form.php", ["title" => "Quote"]);
    }
?>