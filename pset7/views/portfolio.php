<table width="100%" class="table table-striped">
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th> 
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
       </tr>
    </thead>
<?php foreach ($positions as $position): ?>
    <tbody>
        <tr>
            <td><?= $position["symbol"] ?></td>
            <td><?= $position["name"] ?></td>
            <td><?= $position["shares"] ?></td>
            <td>$<?= number_format($position["price"], 2) ?></td>
            <td>$<?= number_format($position["shares"] * $position["price"], 2) ?></td>
        </tr>
<?php endforeach ?>
       <tr>
            <td>Cash</td>
            <td></td>
            <td></td>
            <td></td>
            <td>$<?= number_format($cash, 2) ?></td>
        </tr>
    </tbody>
</table>