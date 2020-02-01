@extends('layout')
@section('boardname','Add Fumetto')

@section('body')
<h1>Inserisci fumetto:</h1><br>
    <form method='POST' action="/fumetti/inserisci">
    @csrf
    Titolo: <input type="text" name="title"><br><br>
    Descrizione: <input type="text" name="descr"><br><br>
    Prezzo: <input type="number" name="price"><br><br>
    <button type="submit">Invia</button>
    </form>
    <br>
    <a href="/fumetti">Home</a>
@endsection