@extends('layout')
@section('boardname','Aggiungi Serie')

@section('body')
<h1>Inserisci serie:</h1><br>
    <form method='POST' action="/serie/inserisci">
    @csrf
    Titolo: <input type="text" name="titolo"><br><br>
    Stagioni: <input type="number" name="stagioni"><br><br>
    Episodi: <input type="number" name="episodi"><br><br>
    <button type="submit">Inserisci</button>
    </form>
    <br>
    <a href="/serie">Home</a>
@endsection