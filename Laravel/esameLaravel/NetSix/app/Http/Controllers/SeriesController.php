<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class SeriesController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $itemlist=\App\Serie::all();
        return view('serie.index',["Serie" => $itemlist]);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        return view('serie.create');
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $serie=new \App\Serie();
        $serie->titolo=$request->titolo;
        $serie->stagioni=$request->stagioni;
        $serie->episodi=$request->episodi;
        $serie->save();
        return redirect('/serie');
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        $item=\App\Serie::find($id);
        return view('serie.show',["serie"=>$item]);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {
        $serie=\App\Serie::find($id);
        return view('serie.edit',["serie"=>$serie]);
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $id)
    {
        $serie=\App\Serie::find($id);
        $serie->titolo=$request->titolo;
        $serie->stagioni=$request->stagioni;
        $serie->episodi=$request->episodi;
        $serie->save();
        return redirect('/serie');
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $item=\App\Serie::find($id);
        $item->delete();
        return redirect('/serie');
    }
}
