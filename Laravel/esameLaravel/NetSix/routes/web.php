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
    return redirect('/serie');
});

Route::get('/serie','SeriesController@index');

Route::post('/serie/inserisci','SeriesController@store');

Route::get('/serie/inserisci','SeriesController@create');

Route::get('/serie/modifica/{id}','SeriesController@edit');

Route::patch('/serie/modifica/{id}','SeriesController@update');

Route::delete('/serie/modifica/{id}','SeriesController@destroy');

Route::get('/serie/info/{id}','SeriesController@show');
