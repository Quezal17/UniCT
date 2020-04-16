@extends('layout')
@section('boardname','Modifica Serie')

@section('body')
<h1>Modifica serie:</h1><br>
    <form method='POST' action="/serie/modifica/{{$serie->id}}">
        @csrf
        @method('PATCH')
        Titolo: <input type="text" name="titolo" value="{{$serie->titolo}}"><br><br>
        Stagioni: <input type="number" name="stagioni" value="{{$serie->stagioni}}"><br><br>
        Episodi: <input type="number" name="episodi" value="{{$serie->episodi}}"><br><br>
        <button type="submit">Modifica</button>
    </form>
    <br>
    <form method='POST' action="/serie/modifica/{{$serie->id}}">
        @csrf
        @method('DELETE')
        <button type="submit">Cancella</button>
    </form>
    <br>
    <a href="/serie">Home</a>
@endsection