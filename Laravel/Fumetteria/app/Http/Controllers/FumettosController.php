<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class FumettosController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index()
    {
        $itemlist=\App\Fumetto::all();
        return view('fumetti.index',["Fumetti" => $itemlist]);
    }

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        return view('fumetti.create');
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        $fumetto=new \App\Fumetto();
        $fumetto->title=$request->title;
        if(!empty($request->descr))
            $fumetto->description=$request->descr;
        $fumetto->price=$request->price;
        $fumetto->save();
        return redirect('/fumetti');
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        $item=\App\Fumetto::find($id);
        return view('fumetti.show',["fumetto"=>$item]);
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {
        $fumetto=\App\Fumetto::find($id);
        return view('fumetti.edit',["fumetto"=>$fumetto]);
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
        $fumetto=\App\Fumetto::find($id);
        $fumetto->title=$request->title;
        $fumetto->description=$request->descr;
        $fumetto->price=$request->price;
        $fumetto->save();
        return redirect('/fumetti');
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        $item=\App\Fumetto::find($id);
        $item->delete();
        return redirect('/fumetti');
    }
}
