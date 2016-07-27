<table width="100%" class="table table-striped">
    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th> 
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
       </tr>
    </thead>
<?php foreach ($history as $transactions): ?>
    <tbody>
        <tr>
            <td><?= $transactions["transaction"] ?></td>
            <td><?= $transactions["time"] ?></td>
            <td><?= $transactions["symbol"] ?></td>
            <td><?= $transactions["shares"] ?></td>
            <td>$<?= number_format($transactions["price"], 2) ?></td>
        </tr>
<?php endforeach ?>
    </tbody>
</table>