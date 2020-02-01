@extends('layout')
@section('boardname','Info Fumetto')

@section('body')
    <h1> Info sul fumetto {{$fumetto->title}}: </h1><br>
    Titolo: {{$fumetto->title}} <br>
    Descrizione: {{$fumetto->description}} <br>
    Prezzo: {{$fumetto->price}} <br>

    <a href="/fumetti">Home</a>
@endsection