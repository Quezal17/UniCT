@extends('layout')
@section('boardname','Info Serie')

@section('body')
    <h1> Info sulla Serie TV {{$serie->titolo}}: </h1><br>
    Titolo: {{$serie->titolo}} <br>
    Stagioni: {{$serie->stagioni}} <br>
    Episodi: {{$serie->episodi}} <br>

    <br><a href="/serie/modifica/{{$serie->id}}">Modifica</a>
    <br><br><a href="/serie">Home</a>
@endsection