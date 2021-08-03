// erl.cpp : Defines the entry point for the application.
//

#include <erl_nif.h>
#include <cstdint>
#include <iostream>
#include "Render.h"
#include "Process.h"


int unitLogin(int64_t uid, double x, double y) {

	return 0;
}

int unitLogout(int64_t y) {

	return 0;

}

int init(uint64_t processPtr) {
	auto subProcess = (Process*)processPtr;
	subProcess->init();
	return 0;
}

static ERL_NIF_TERM unitLogin_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
	int ret;
	int64_t uid; double x; double y;
	if (!enif_get_int64(env, argv[0], &uid)) {
		return enif_make_badarg(env);
	}
	if (!enif_get_double(env, argv[1], &x)) {
		return enif_make_badarg(env);
	}
	if (!enif_get_double(env, argv[1], &y)) {
		return enif_make_badarg(env);
	}
	ret = unitLogin(uid, x, y);
	return enif_make_int(env, ret);
}

static ERL_NIF_TERM unitLogout_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
	int ret;
	int64_t uid;
	if (!enif_get_int64(env, argv[0], &uid)) {
		return enif_make_badarg(env);
	}
	ret = unitLogout(uid);
	return enif_make_int(env, ret);
}

static ERL_NIF_TERM init_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
	uint64_t y;
	int ret;
	if (!enif_get_uint64(env, argv[0], &y)) {
		return enif_make_badarg(env);
	}
	ret = init(y);
	return enif_make_int(env, ret);
}

static ErlNifFunc nif_funcs[] = {
		{"unitLogin", 1, unitLogin_nif},
		{"unitLogout", 1, unitLogout_nif},
		{"init", 1, init_nif}
};

ERL_NIF_INIT(mhslg_map, nif_funcs, NULL, NULL, NULL, NULL)