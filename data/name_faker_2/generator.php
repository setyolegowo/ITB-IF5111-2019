<?php
// header('Content-type: text/plain');
require_once 'C:\Users\hanifan\Kuliah\S2\Analisis Algoritma\python_faker\vendor\fzaninotto\faker\src\autoload.php';
$faker = Faker\Factory::create();

$n_batch = 10000;
$file = fopen("daftar_rumah.large.csv","a");
for($batch=0; $batch<$n_batch; $batch++) {
    for($i=0; $i<1000; $i++) {
        $male = $faker->name($gender='male');
        $female = $faker->name($gender='female');
        $line = $male.','.$female.',';
        fputcsv($file,explode(',',$line));
    }
    echo $batch."\n";
}
fclose($file);


