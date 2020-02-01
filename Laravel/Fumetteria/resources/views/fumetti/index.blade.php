@extends('layout')
@section('boardname','Index')

@section('body')
<h1> Lista Fumetti </h1>
    <ul>
        @foreach($Fumetti as $item)
            <li> <a href="/fumetti/modifica/{{$item->id}}">{{$item->title}}</a>, {{$item->description}}, {{$item->price}} </li>
        @endforeach
    </ul>
    <br>
    <a href="/fumetti/inserisci">Inserisci</a>
@endsection