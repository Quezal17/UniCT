@extends('layout')
@section('boardname','Index')

@section('body')
<h1> Lista Serie TV </h1>
    <ul>
        @foreach($Serie as $item)
            <li> <a href="/serie/info/{{$item->id}}">{{$item->titolo}}</a></li>
        @endforeach
    </ul>
    <br>
    <a href="/serie/inserisci">Inserisci nuova serie</a>
@endsection