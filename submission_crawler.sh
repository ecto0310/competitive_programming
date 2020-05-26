#!/bin/bash

get_extension() {
  case "$1" in
  *JavaScript*) echo "js" ;;
  *MoonScript*) echo "moon" ;;
  *TypeScript*) echo "ts" ;;
  *Brainfuck*) echo "bf" ;;
  *Objective*) echo "m" ;;
  *Unlambda*) echo "unl" ;;
  *Clojure*) echo "clj" ;;
  *Crystal*) echo "cr" ;;
  *Fortran*) echo "f" ;;
  *Haskell*) echo "hs" ;;
  *Delphi*) echo "pas" ;;
  *Kotlin*) echo "kt" ;;
  *Octave*) echo "m" ;;
  *Python*) echo "py" ;;
  *Pascal*) echo "pas" ;;
  *Scheme*) echo "ss" ;;
  *Basic*) echo "vb" ;;
  *COBOL*) echo "cobol" ;;
  *Julia*) echo "jl" ;;
  *OCaml*) echo "ml" ;;
  *Swift*) echo "swift" ;;
  *Scala*) echo "scala" ;;
  *Bash*) echo "sh" ;;
  *Java*) echo "java" ;;
  *Lisp*) echo "lisp" ;;
  *Perl*) echo "pl" ;;
  *Ruby*) echo "rb" ;;
  *Rust*) echo "rs" ;;
  *Text*) echo "txt" ;;
  *Awk*) echo "awk" ;;
  *C++*) echo "cpp" ;;
  *Nim*) echo "nim" ;;
  *PHP*) echo "php" ;;
  *Sed*) echo "sed" ;;
  *C#*) echo "cs" ;;
  *F#*) echo "fs" ;;
  *Go*) echo "go" ;;
  *ML*) echo "sml" ;;
  *C*) echo "c" ;;
  *D*) echo "d" ;;
  **) echo "unknown" ;;
  esac
}

IFS=$'\n'

git config --global user.name "ecto0310"
git config --global user.email "ecto0310@gmail.com"
git remote set-url origin https://ecto0310:${GITHUB_TOKEN}@github.com/ecto0310/competitive_programming.git
git checkout -b master

new_submissions="[]"

at_username="ecto0310"
cf_username="ecto0310"
aoj_username="ecto0310"

at_submissions=$(
  curl -so- --compressed https://kenkoooo.com/atcoder/atcoder-api/results?user=${at_username} |
    jq -c '.[]'
)

exists=()

for exists_id in $(ls -1R "atcoder" | grep -E ^[0-9]\{7,\}\\. | cut -d . -f 1); do
  exists[${exists_id}]=1
done

for at_submission in ${at_submissions}; do
  for cmd in $(echo ${at_submission} | jq -r 'to_entries|map("\(.key)=\"\(.value)\"")|.[]'); do
    eval ${cmd}
  done

  if [ "${result}" != "AC" ] || [ "${exists[${id}]}" = "1" ]; then
    continue
  fi

  new_submissions=$(echo ${new_submissions} | jq '.|=.+[{"site":"AtCoder","time":"'${epoch_second}'","id":"'${id}'","contest_id":"'${contest_id}'","problem_id":"'${problem_id}'","language":"'${language}'"}]')
done

cf_submissions=$(
  curl -so- https://codeforces.com/api/user.status?handle=${cf_username} |
    jq -c '.result[]'
)

exists=()

for exists_id in $(ls -1R "codeforces" | grep -E ^[0-9]\{7,\}\\. | cut -d . -f 1); do
  exists[${exists_id}]=1
done

for cf_submission in ${cf_submissions}; do
  cf_submission=$(echo ${cf_submission} | jq '.|=.+{"index":(.problem.index)}|del(.problem)|del(.author)')
  for cmd in $(echo ${cf_submission} | jq -r 'to_entries|map("\(.key)=\"\(.value)\"")|.[]'); do
    eval ${cmd}
  done

  if [ "${verdict}" != "OK" ] || [ "${exists[${id}]}" = "1" ]; then
    continue
  fi

  new_submissions=$(echo ${new_submissions} | jq '.|=.+[{"site":"Codeforces","time":"'${creationTimeSeconds}'","id":"'${id}'","contest_id":"'${contestId}'","problem_id":"'${contestId}'_'${index,,}'","language":"'${programmingLanguage}'"}]')
done

aoj_submissions=$(
  curl -so- --compressed https://judgeapi.u-aizu.ac.jp/solutions/users/${aoj_username} |
    jq -c '.[]'
)

exists=()

for exists_id in $(ls -1R "aizu_online_judge" | grep -E ^[0-9]\{7,\}\\. | cut -d . -f 1); do
  exists[${exists_id}]=1
done

for aoj_submission in ${aoj_submissions}; do
  for cmd in $(echo ${aoj_submission} | jq -r 'to_entries|map("\(.key)=\"\(.value)\"")|.[]'); do
    eval ${cmd}
  done

  if [ "${exists[${judgeId}]}" = "1" ]; then
    continue
  fi

  new_submissions=$(echo ${new_submissions} | jq '.|=.+[{"site":"AOJ","time":"'${submissionDate:0:10}'","id":"'${judgeId}'","problem_id":"'${problemId}'","language":"'${language}'"}]')
done

new_submissions=$(echo ${new_submissions} | jq -c 'sort_by(.time) | .[]')

count=0

for new_submission in ${new_submissions}; do
  for cmd in $(echo ${new_submission} | jq -r 'to_entries|map("\(.key)=\"\(.value)\"")|.[]'); do
    eval ${cmd}
  done

  echo "Fetching submission #${id}(${site})"

  if [ "${site}" = "AtCoder" ]; then
    header="// URL: https://atcoder.jp/contests/${contest_id}/submissions/${id}"$'\n'"// Date: $(date -d @${time} -R)"$'\n'"// Language: ${language}"
    directory="atcoder/${contest_id}/${problem_id}"
    filename="${directory}/${id}.$(get_extension ${language})"
    code=$(
      curl -so- "https://atcoder.jp/contests/${contest_id}/submissions/${id}" |
        dos2unix |
        xmllint --xpath '//*[@id="submission-code"]/text()' --html - 2>/dev/null |
        sed 's/&amp;/\&/g; s/&lt;/\</g; s/&gt;/\>/g; s/&quot;/\"/g; s/#&#39;/\'"'"'/g;'
    )

  elif [ "${site}" = "Codeforces" ]; then
    header="// URL: https://codeforces.com/contest/${contest_id}/submission/${id}"$'\n'"// Date: $(date -d @${time} -R)"$'\n'"// Language: ${language}"
    directory="codeforces/${contest_id}/${problem_id}"
    filename="${directory}/${id}.$(get_extension ${language})"
    code=$(
      curl -so- "https://codeforces.com/contest/${contest_id}/submission/${id}" |
        dos2unix |
        xmllint --xpath '//*[@id="program-source-text"]/text()' --html - 2>/dev/null |
        sed 's/&amp;/\&/g; s/&lt;/\</g; s/&gt;/\>/g; s/&quot;/\"/g; s/#&#39;/\'"'"'/g;'
    )

  elif [ "${site}" = "AOJ" ]; then
    header="// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=${id}"$'\n'"// Date: $(date -d @${time} -R)"$'\n'"// Language: ${language}"
    directory="aizu_online_judge/${problem_id}"
    filename="${directory}/${id}.$(get_extension ${language})"
    code=$(
      curl -so- "https://judgeapi.u-aizu.ac.jp/reviews/${id}" |
        dos2unix |
        jq -r '.sourceCode'
    )
  fi

  mkdir -p "${directory}"
  echo "${header}"$'\n'"${code}" >${filename}

  git add -A
  git commit -a -m "Add ${filename}" --date="$(date -d @${time} -R)"

  let count++

  sleep 0.5
done

git rebase --committer-date-is-author-date HEAD~${count}
git push origin master

echo "Successfully all process"
