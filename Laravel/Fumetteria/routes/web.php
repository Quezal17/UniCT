<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});

Route::get('/fumetti','FumettosController@index');

Route::post('/fumetti/inserisci','FumettosController@store');

Route::get('/fumetti/inserisci','FumettosController@create');

Route::get('/fumetti/modifica/{name}','FumettosController@edit');

Route::patch('/fumetti/modifica/{name}','FumettosController@update');

Route::delete('/fumetti/modifica/{name}','FumettosController@destroy');

Route::get('/fumetti/info/{id}','FumettosController@show');




