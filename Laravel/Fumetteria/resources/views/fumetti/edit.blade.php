@extends('layout')
@section('boardname','Modifica Fumetto')

@section('body')
<h1>Modifica fumetto:</h1><br>
    <form method='POST' action="/fumetti/modifica/{{$fumetto->id}}">
        @csrf
        @method('PATCH')
        Titolo: <input type="text" name="title" value="{{$fumetto->title}}"><br><br>
        Descrizione: <input type="text" name="descr" value="{{$fumetto->description}}"><br><br>
        Prezzo: <input type="number" name="price" value="{{$fumetto->price}}"><br><br>
        <button type="submit">Modifica</button>
    </form>
    <br>
    <form method='POST' action="/fumetti/modifica/{{$fumetto->id}}">
        @csrf
        @method('DELETE')
        <button type="submit">Cancella</button>
    </form>
    <br>
    <a href="/fumetti">Home</a>
    <br>
    <a href="/fumetti/info/{{$fumetto->id}}">info</a>
@endsection